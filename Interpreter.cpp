//
//  Interpreter.cpp
//  Project3
//
//  Created by Michael Bird on 7/21/14.
//  Copyright (c) 2014 Michael Bird. All rights reserved.
//

#include "Interpreter.h"

Interpreter::Interpreter() {};
Interpreter::~Interpreter() {};

void Interpreter::interpret(DataLog obj_) {
    DL_obj = obj_;
    queries_ = DL_obj.get_queries();
    
    add_relation();
    
    Relations_ = DAT.get_relations();
    
    eval_query();
}

void Interpreter::add_relation() { // add a relation
    
    schemes_ = DL_obj.get_schemes();
    
    for (auto scheme: schemes_) {
        
        Scheme SC;
        
        for (auto parameter: scheme.get_parameters()) {
           
            for (auto value: parameter) {
               
               stringstream ss; ss << value;
               SC.push_back(ss.str());
               
            }
        }
        
        vector<Tuple> tuplevec = add_facts(scheme.get_id());
        DAT.create_new_relation(scheme.get_id(), SC, tuplevec);
        tuple_clear();
        
    }
}

vector<Tuple> Interpreter::add_facts(string id) {
    
    facts_ = DL_obj.get_facts(); // checks for tuples in the relation
    
    for (auto fact: facts_) {
        
        Tuple TU;
        
        if(id == fact.get_id()) {
            
            for (auto parameter: fact.get_parameters()) {
                TU.push_back(parameter);
                
            }
            
        tuple_vector.push_back(TU);
        
        }
    }
    
    return tuple_vector;
    
}

void Interpreter::tuple_clear() {
    
    tuple_vector.clear();

}

void Interpreter::eval_query() {
        
    for (auto query: queries_) {
        Relation RelTemp;
        RelTemp = Relations_[query.get_id()];
        
        stringstream ss;
        
        RelTemp.name = query.get_id();
        
        ss << RelTemp.name << "(";
        
        vector<string> parameters = query.get_parameters();
        int count = 0;
        for (int j=0; j < parameters.size(); j++) {
            
            ss << parameters[j];
            
            if (is_string(parameters[j]) == true) {
             
                RelTemp = RelTemp.select(count,parameters[j]);
                
            }
            else {
                for (int k = (j+1); k < parameters.size(); k++) {
                    if (parameters[k] == parameters[j]) {
                        RelTemp = RelTemp.select(k, j);
                    }
                }
                variable_pos.push_back(j);
                variable_name.push_back(parameters[j]);
            }
            count++;
            if(count == 1)
                ss << ",";
        }
        ss << ")?";
        set<Tuple> tupleset = RelTemp.get_tuples();
        if(tupleset.size() >= 1)
            ss << " YES(" << tupleset.size() <<")";
        else
            ss << " No";
        cout << ss.str() << endl;
        if(variable_pos.size() > 0)
            RelTemp.project(variable_name, variable_pos);
        variable_pos.clear();
        variable_name.clear();
    }
}

bool Interpreter::is_string(string param) {
    
    bool bvalue = false;
     
        if(isalpha(param.at(0)))
            bvalue = false;
        else
            bvalue = true;
    return bvalue;
}
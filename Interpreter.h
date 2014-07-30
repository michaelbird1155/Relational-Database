//
//  Interpreter.h
//  Project3
//
//  Created by Michael Bird on 7/21/14.
//  Copyright (c) 2014 Michael Bird. All rights reserved.
//

#ifndef __Project3__Interpreter__
#define __Project3__Interpreter__

#include <iostream>
#include <sstream>
#include <set>
#include <fstream>
#include <ctype.h>
#include "DatalogProgram.h"
#include "Database.h"
#include "Scheme.h"
#include "Tuple.h"
#include "Relation.h"

class Interpreter {
    
public:
    
    Interpreter();
    ~Interpreter();
    
    void interpret(DataLog obj);
    vector<Tuple> add_facts(string id);
    void add_relation();
    void tuple_clear();
    void eval_query(char* filename);
    bool is_string(string param);
    string yes_no(set<Tuple> set);
    
private:
    
    vector<string> variable_name;
    vector<int> variable_pos;
    vector<Tuple> tuple_vector;
    
    DataLog DL_obj;
    Database DAT;
    Relation REL;
    map<string, Relation> Relations_;
    vector<Predicate> schemes_;
    vector<Predicate> facts_;
    vector<Predicate> queries_;
    
};




#endif /* defined(__Project3__Interpreter__) */

//
//  Relation.cpp
//  Project2
//
//  Created by Michael Bird on 7/21/14.
//  Copyright (c) 2014 Michael Bird. All rights reserved.
//

#include "Relation.h"

Relation::Relation() {}
Relation::~Relation() {}

void Relation::add_tuple(vector<Tuple> tuple) {
    for(auto tuple_item : tuple) {
        tuples.insert(tuple_item);
    }
}
void Relation::add_tuple(Tuple tuple) {
    tuples.insert(tuple);
}
void Relation::add_scheme(Scheme scheme_in) {
    
    scheme = scheme_in;
    
}
Relation Relation::select(int pos, string value) {
    
    Relation R;
    for (auto tuple : tuples ) {
       if(tuple[pos] == value ){
           R.add_tuple(tuple);
        }
    }
    return  R;
}

Relation Relation::select(int pos1, int pos2) {
    Relation R;
    for (auto tuple : tuples ) {
        if(tuple[pos1] == tuple[pos2] ){
            R.add_tuple(tuple);
        }
    }
    return  R;
    
}
string Relation::project(vector<string> name, vector<int> pos) {
    
    stringstream ss;
    for (auto tuple : tuples) {
        for (unsigned int i = 0; i < name.size(); i++) {
            
           if(i == 0)
                ss << "  "<<name[i] << "=" << tuple[pos[i]];
           else
                ss << ", "<<name[i] << "=" << tuple[pos[i]];
        }
        ss << "\n";
    }
    return ss.str();
}

set<Tuple> Relation::get_tuples() {
    return tuples;
}


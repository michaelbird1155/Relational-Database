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
void Relation::project(vector<string> name, vector<int> pos) {
    for (auto tuple : tuples ) {
        for (auto spot : pos) {
            for(auto row: name[spot]) {
                cout << "  "<<name[spot] << "=" << tuple[spot];
            }
         
        } cout << endl;
    }
}

set<Tuple> Relation::get_tuples() {
    return tuples;
}


//
//  Database.cpp
//  Project2
//
//  Created by Michael Bird on 7/21/14.
//  Copyright (c) 2014 Michael Bird. All rights reserved.
//

#include "Database.h"

Database::Database() {};

Database::~Database() {};

void Database::create_new_relation(string name, Scheme scheme, vector<Tuple> tuplevec) {
    
    Relation REL;
    REL.add_scheme(scheme);
    REL.add_tuple(tuplevec);
    Relations[name] = REL;
   
}

map<string, Relation> Database::get_relations() {
    return Relations;
}
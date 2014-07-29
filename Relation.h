//
//  Relation.h
//  Project2
//
//  Created by Michael Bird on 7/21/14.
//  Copyright (c) 2014 Michael Bird. All rights reserved.
//

#ifndef __Project2__Relation__
#define __Project2__Relation__

#include <iostream>
#include <set>
#include <ctype.h>
#include "Tuple.h"
#include "Scheme.h"
#include "Predicate.h"
#include <map>

using namespace std;

class Relation {
    
public:
    
    Relation();
    ~Relation();
    
    void add_tuple(vector<Tuple> tuple);
    void add_tuple(Tuple tuple);
    void add_scheme(Scheme);
    
    set<Tuple> get_tuples();
    
    Relation select(int pos, string value);
    Relation select(int pos1, int pos2);
    void project(vector<string> name, vector<int> pos);
    void rename();
    
    string name;
   
    
private:
    
    vector<Predicate> queries_;
    Scheme scheme;
    set<Tuple> tuples;
    
};



#endif /* defined(__Project2__Relation__) */
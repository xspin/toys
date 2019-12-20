#ifndef __cal_H__
#define __cal_H__

#include <vector>
#include <cstdio>
#include <iostream>

class ExprAST {
    bool isleaf;
    int op;
    std::string mark;
    std::vector<ExprAST*> childs;

public:
    ExprAST(int op) {
        this->op = op;
        isleaf = true;
        switch(op) {
            case MINUS: mark = "MINUS"; break;
            case PLUS: mark = "PLUS"; break;
            case TIMES: mark = "TIMES"; break;
            case DIVIDE: mark = "DIVIDE"; break;
            case MODULO: mark = "MODULO"; break;
            case BRACKET: mark = "BRACKET"; break;
            default: mark = "UNK"; break;
        }
    }

    void insert(ExprAST* a=NULL, ExprAST* b=NULL) {
        if(a) childs.push_back(a);
        if(b) childs.push_back(b);
        if(a || b) isleaf = false;
    }

    void print(std::vector<int> &s, int d=0, bool isleaf=true) {
        std::cout << "  ";
        for(int i=1, k=1; i<s.size(); k++) {
            if(k == s[i]) {
                std::cout << "│   ";
                i++;
            } else {
                std::cout << "    ";
            }
            if(k == -s[i]) i++;
        }
        if(d>0) {
            if(isleaf) std::cout << "└── ";
            else std::cout << "├── ";
        }
        if(mark=="UNK") std::cout << op << std::endl;
        else std::cout << mark << std::endl;
        s.push_back(isleaf?-d:d);
        for(auto &a : childs) {
            a->print(s, d+1, a==childs.back());
        }
        s.pop_back();
    }

};

#endif


/*
1-2+3-4*5/6-7%8 + (9) - (1+2-3*4/5)
*/
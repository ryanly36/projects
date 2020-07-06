#include "Jug.h"

Jug::Jug(int a,int b,int c,int d,int e,int f,int g,int h,int i) {
	capA = a;
    capB = b;
    goal = c;
    cFillA = d;
    cFillB = e;
    cEmptyA = f;
    cEmptyB = g;
    cPourAB = h;
    cPourBA = i;
    Node* fA = new Node("fill A");
    Node* fB = new Node("fill B");
    Node* eA = new Node("empty A");
    Node* eB = new Node("empty B");
    Node* pAB = new Node("pour A B");
    Node* pBA = new Node("pour B A");
    actions.push_back(fA);
    actions.push_back(fB);
    actions.push_back(eA);
    actions.push_back(eB);
    actions.push_back(pAB);
    actions.push_back(pBA);
}


Jug::~Jug() {
	for (unsigned i = 0; i < actions.size(); ++i) {
		delete actions.at(i);
	}
}


int Jug::solve(string &solution) {
	solution = ""; 
	if (cFillA < 0 || cFillB < 0 || cEmptyA < 0 || cEmptyB < 0 || cPourAB < 0 || cPourBA < 0) {
		return -1;
	}
	if (!(0 < capA && capA <= capB)) {
		return -1;
	}
	if (!(goal <= capB && capB <= 1000)) {
		return -1;
	}
	const string& temp = solution;
	solution = solve(temp);
	if (solution == "") {
		return 0;
	}
	return 1;
}

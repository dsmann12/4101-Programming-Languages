// Tree.cpp -- the implementation of the tree classes

#include "Tree.h"
#include "Special.h"


void
BoolLit::print(int n) {
  // There got to be a more efficient way to print n spaces.
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << (boolVal ? "#t" : "#f") << endl;
}


void
IntLit::print(int n) {
  // There got to be a more efficient way to print n spaces.
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << intVal << endl;
}


void
StrLit::print(int n) {
  // There got to be a more efficient way to print n spaces.
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << '"' << strVal << '"' << endl;
}


void
Ident::print(int n) {
  // There got to be a more efficient way to print n spaces.
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << name << endl;
}


void
Nil::print(int n, bool p) {
  // There got to be a more efficient way to print n spaces.
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << (p ? ")" : "()") << endl;
}


void
Cons::print(int n) {
  form->print(this, n, FALSE);
}


void
Cons::print(int n, bool p) {
  form->print(this, n, p);
}


void
Cons::parseList() {
  // TODO: implement this function and any helper functions you might need.
}

// Tree.h -- the parse tree node data structure
//
// Defines the types
//
//   class Node;
//   class BoolLit : public Node;
//   class IntLit : public Node;
//   class StrLit : public Node;
//   class Ident : public Node;
//   class Nil : public Node;
//   class Cons : public Node;

#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

#ifndef NULL
#define NULL 0
#endif
#define FALSE 0
#define TRUE  1

// Since Special.h #includes Tree.h, we can only have a forward declaration
// of class Special here.  We therefore cannot have any method calls on
// objects of the Special hierarchy.  We can only declare pointers of type
// Special*.

class Special;


class Node {
 public:
  // The argument of print(int) is the number of characters to indent.
  // Every subclass of Node must implement print(int).
  virtual void print(int n) = 0;

  // The first argument of print(int, bool) is the number of characters
  // to indent.  It is interpreted the same as for print(int).
  // The second argument is only useful for lists (nodes of classes
  // Cons or Nil).  For all other subclasses of Node, the boolean
  // argument is ignored.  Therefore, print(n,p) defaults to print(n)
  // for all classes other than Cons and Nil.
  // For classes Cons and Nil, print(n,TRUE) means that the open
  // parenthesis was printed already by the caller.
  // Only classes Cons and Nil override print(int,bool).
  // For correctly indenting special forms, you might need to pass
  // additional information to print.  What additional information
  // you pass is up to you.  If you only need one more bit, you can
  // encode that in the sign bit of n.  If you need additional parameters,
  // make sure that you define the method print in all the appropriate
  // subclasses of Node as well.
  virtual void print(int n, bool p) { print(n); }

  // For parsing Cons nodes, for printing trees, and later for
  // evaluating them, we need some helper functions that test
  // the type of a node and that extract some information.

  // TODO: implement these in the appropriate subclasses to return TRUE.
  virtual bool isBool()   { return FALSE; }  // BoolLit
  virtual bool isNumber() { return FALSE; }  // IntLit
  virtual bool isString() { return FALSE; }  // StringLit
  virtual bool isSymbol() { return FALSE; }  // Ident
  virtual bool isNull()   { return FALSE; }  // Nil
  virtual bool isPair()   { return FALSE; }  // Cons

  // TODO: Report an error in these default methods and implement them
  // in class Cons.  After setCar, a Cons cell needs to be `parsed' again
  // using parseList.
  virtual Node * getCar() { return NULL; }
  virtual Node * getCdr() { return NULL; }
  virtual void setCar(Node * a) { }
  virtual void setCdr(Node * d) { }
};


class BoolLit : public Node {
 private:
  bool boolVal;

 public:
  BoolLit(bool b) { boolVal = b;  }

  virtual void print(int n);
};


class IntLit : public Node {
 private:
  int intVal;

 public:
  IntLit(int i) { intVal = i; }

  virtual void print(int n);
};


class StrLit : public Node {
 private:
  char * strVal;

 public:
  StrLit(char * s) { strVal = s; }

  virtual void print(int n);
};


class Ident : public Node {
 private:
  char * name;

 public:
  Ident(char * n) { name = n; }

  virtual void print(int n);
};


class Nil : public Node {
 public:
  Nil() { }

  virtual void print(int n)		{ print(n, FALSE); }
  virtual void print(int n, bool p);
};


class Cons : public Node {
 private:
  Node * car;
  Node * cdr;
  Special * form;
  
  // parseList() `parses' special forms, constructs an appropriate
  // object of a subclass of Special, and stores a pointer to that
  // object in variable form.  It would be possible to fully parse
  // special forms at this point.  Since this causes complications
  // when using (incorrect) programs as data, it is easiest to let
  // parseList only look at the car for selecting the appropriate
  // object from the Special hierarchy and to leave the rest of
  // parsing up to the interpreter.
  void parseList();
  // TODO: Add any helper functions for parseList as appropriate.

 public:
  Cons(Node * a, Node * d) { car = a;  cdr = d;  parseList();}

  virtual void print(int n);
  virtual void print(int n, bool p);
};

#endif

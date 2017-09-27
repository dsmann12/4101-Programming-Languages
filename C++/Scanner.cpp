// Scanner.cpp -- the implementation of class Scanner

#include <iostream>
#include <string.h>
#include <ctype.h>

#include "Scanner.h"

Token * 
Scanner::getNextToken() {
  char ch;  

  // It would be more efficient if we'd maintain our own input buffer
  // and read characters out of that buffer, but reading individual
  // characters from the input stream is easier.
  in->get(ch);

  // TODO: skip white space and comments

  if (in->eof())
    return NULL;

  // Special characters
  else if (ch == '\'')
    return new Token(QUOTE);
  else if (ch == '(')
    return new Token(LPAREN);
  else if (ch == ')')
    return new Token(RPAREN);
  else if (ch == '.')
    // We ignore the special identifier `...'.
    return new Token(DOT);

  // Boolean constants
  else if (ch == '#') {
    in->get(ch);
    if (ch == 't')
      return new Token(TRUET);
    else if (ch == 'f')
      return new Token(FALSET);
    else {
      cerr << "Illegal character '" << ch << "' following #" << endl;
      return getNextToken();
    }
  }

  // String constants
  else if (ch == '"') {
    // TODO: scan a string into the buffer variable buf
    return new StrToken(buf);
  }

  // Integer constants
  else if (ch >= '0' && ch <= '9') {
    int i = ch - '0';
    // TODO: scan the number and convert it to an integer

    // put the character after the integer back into the input
    // in->putback(ch);
    return new IntToken(i);
  }

  // Identifiers
  else if (ch >= 'A' && ch <= 'Z'
	   /* or ch is some other valid first character for an identifier */) {
    // TODO: scan an identifier into the buffer

    // put the character after the identifier back into the input
    // in->putback(ch);
    return new IdentToken(buf);
  }

  // Illegal character
  else {
    cerr << "Illegal input character '" << ch << '\'' << endl;
    return getNextToken();
  }
}

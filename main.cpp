#include <string>

//===----------------------------------------------------------------------===//
// Lexer
//===----------------------------------------------------------------------===//

// The lexer returns tokens [0-255] if an unknown character is encountered, otherwise
// one of these is returned for known constructs.
enum Token {
	tok_eof = -1,

	// Commands
	tok_def = -2,
	tok_extern = -3,

	// Primary
	tok_identifier = -4,
	tok_number = -5
};

// We use global variables to hold the value of an identifier or number when we
// encounter them while lexing. This is not the best approach - we will refine this later.

static std::string IdentifierStr; // Filled if construct is tok_identifier
static double NumVal;             // Filled if construct is tok_number

// gettok - Return the next token from standard input.
static int gettok() {
	static int LastChar = ' ';

	// Skip whitespace
	while (isspace(LastChar))
		LastChar = getchar();
	
	if (isalpha(LastChar)) { // Identifier: [a-zA-Z][a-zA-Z0-9]*
		IdentifierStr = LastChar;

		while (isalnum((LastChar = getchar())))
			IdentifierStr += LastChar;
		
		if (IdentifierStr == "def")
			return tok_def;
		
		if (IdentifierStr == "extern")
			return tok_extern;
		
		return tok_identifier;
	}

	if (isdigit(LastChar) || LastChar == '.') { // Number: [0-9.]+
		std::string NumStr;

		do {
			NumStr += LastChar;
			LastChar = getchar();
		} while (isdigit(LastChar) || LastChar == '.');

		NumVal = strtod(NumStr.c_str(), nullptr);
		return tok_number;
	}

	if (LastChar == '#') {
		// Comment until end of line
		do
			LastChar = getchar();
		while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

		if (LastChar != EOF)
			return gettok();
	}

	if (LastChar == EOF)
		return tok_eof;
	
	// Otherwise, just return the character as its ascii value.
	int ThisChar = LastChar;
	LastChar = getchar();
	return ThisChar;
}

int main() {
	return 0;
}
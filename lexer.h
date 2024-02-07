#ifndef LEXER_H
#define LEXER_H

#include <string>

// Different kinds of tokens the lexer will identify.
enum TokenKind {
    TOK_EOF = -1,
    TOK_DEF = -2,
    TOK_EXTERN = -3,
    TOK_IDENTIFIER = -4,
    TOK_NUMBER = -5,
    TOK_OTHER = -6
};

// Token returned by the lexer.
class Token {
    public:
        // Token constructor, which accepts the kind and value.
        Token(TokenKind kind, std::string value) {
            _kind = kind;
            _value = value;
        }

        // Get the kind of this token
        inline TokenKind get_kind() {
            return _kind;
        }

        // Get the value of this token. We use the word 'raw' as a reminder
        // that it needs to be cast to the appropriate type first.
        inline std::string get_string_value() {
            return _value;
        }
    private:
        // The kind of this token.
        TokenKind _kind;

        // The value of this token. It could be anything - we'll apply
        // the correct cast when necessary using the kind above.
        std::string _value;
};

// Lexes a string input and can be used to stream a string input as tokens, which
// will then be used by the parser (not implemented yet).
class Lexer {
    public:
        // Constructs the lexer, accepting a reference to an input string as an argument.
        Lexer(const std::string &input): _input(input) { }

        // Return the next token, eating it in the process.
        Token next_token();
    private:
        // Reference to the string input. Note that this reference will not change
        // because a new lexer will be constructed for every new input.
        const std::string &_input;
};

#endif // LEXER_H

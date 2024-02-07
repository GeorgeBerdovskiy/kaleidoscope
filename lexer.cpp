#include "lexer.h"

Token Lexer::next_token() {
    char last_char = ' ';

    // Skip whitespace
    while (isspace(last_char)) {
        // Get the next character from input
        last_char = getchar();
    }

    // We've encountered a character that isn't whitespace... what is it?
    if (isalpha(last_char)) {
        // It's some kind of identifier. Let's build the rest of it!
        std::string identifier = "";

        // Grab more characters while they are alphanumeric
        while (isalnum(last_char)) {
            identifier += last_char;
            last_char = getchar();
        }

        // Now check what identifier we have
        if (identifier == "def")
            return Token(TOK_DEF, "");
        
        if (identifier == "extern")
            return Token(TOK_EXTERN, "");

        return Token(TOK_IDENTIFIER, identifier);
    }

    if (isdigit(last_char) || last_char == '.') {
        // We've encountered the beginning of what seems to be a number.
        // Remember that all numbers in our language are floating point - we don't
        // distinguish between integers and naturals.
        std::string number_str;

        do {
            number_str += last_char;
            last_char = getchar();
        } while(isdigit(last_char) || last_char == '.');

        return Token(TOK_NUMBER, number_str);
    }

    if (last_char == '#') {
        // Comment until the end of the line
        do {
            last_char = getchar();
        } while (last_char != EOF && last_char != '\n' && last_char != '\r');

        if (last_char != EOF)
            return next_token();
    }

    // Otherwise, just return the character as its ASCII value.
    // NOTE - This is pretty different from Kaleidoscope... make sure it works
    // the same way with thorough testing.
    return Token(TOK_OTHER, std::string(1, last_char));
}

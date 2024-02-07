#include <string>
#include <iostream>

#include "lexer.h"

int main() {
	while (true) {
		std::string input;

		std::cout << "> ";
		std::cin >> input;

		Lexer lexer = Lexer(input);
		Token next_token = lexer.next_token();

		while (next_token.get_kind() != TOK_EOF) {
			switch next_token {
			case TOK_DEF:
				std::cout << "[DEBUG] Function definition keyword\n";
				break;
			case TOK_EXTERN
				std::cout << "[DEBUG] External (library) keyword\n";
				break;
			default:
				std::cout << "[DEBUG] Other token encountered\n";
			}
		}
	}

	/*while (true) {
		int next_token = Lexer::gettok();
		switch (next_token) {
			case TOK_EOF:
			std::cout << "END OF FILE\n";
			break;
			case ';':
			std::cout << "SEMICOLON\n";
			break;
			case TOK_DEF:
			std::cout << "DEF\n";
			break;
			case TOK_EXTERN:
			std::cout << "EXTERN\n";
			break;
			default:
			std::cout << "SOMETHING ELSE -" << next_token << "\n";
			break;
			}
	}*/

	return 0;
}
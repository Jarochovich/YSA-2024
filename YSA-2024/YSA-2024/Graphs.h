#pragma once

#define FST_MAIN(string) FST::FST(string, LEXSEMA_MAIN, 5, \
FST::NODE(1, FST::RELATION('m', 1)), \
FST::NODE(1, FST::RELATION('a', 2)), \
FST::NODE(1, FST::RELATION('i', 3)), \
FST::NODE(1, FST::RELATION('n', 4)), \
FST::NODE())

#define FST_FUNCTION(string) FST::FST(string, LEXSEMA_FUNCTION, 9, \
FST::NODE(1, FST::RELATION('f', 1)), \
FST::NODE(1, FST::RELATION('u', 2)), \
FST::NODE(1, FST::RELATION('n', 3)), \
FST::NODE(1, FST::RELATION('c', 4)), \
FST::NODE(1, FST::RELATION('t', 5)), \
FST::NODE(1, FST::RELATION('i', 6)), \
FST::NODE(1, FST::RELATION('o', 7)), \
FST::NODE(1, FST::RELATION('n', 8)), \
FST::NODE())

#define FST_VAR(string) FST::FST(string, LEXSEMA_VAR, 4, \
FST::NODE(1, FST::RELATION('v', 1)), \
FST::NODE(1, FST::RELATION('a', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE())

#define FST_STR(string) FST::FST(string, LEXSEMA_STR, 4, \
FST::NODE(1, FST::RELATION('s', 1)), \
FST::NODE(1, FST::RELATION('t', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE())

#define FST_SHORT(string) FST::FST(string, LEXSEMA_SHORT, 6, \
FST::NODE(1, FST::RELATION('s', 1)), \
FST::NODE(1, FST::RELATION('h', 2)), \
FST::NODE(1, FST::RELATION('o', 3)), \
FST::NODE(1, FST::RELATION('r', 4)), \
FST::NODE(1, FST::RELATION('t', 5)), \
FST::NODE())

#define FST_IF(string) FST::FST(string, LEX_IF, 3, \
FST::NODE(1, FST::RELATION('i', 1)), \
FST::NODE(1, FST::RELATION('f', 2)), \
FST::NODE())

#define FST_WRITE(string) FST::FST(string, LEXSEMA_CP, 13, \
FST::NODE(1, FST::RELATION('c', 1)), \
FST::NODE(1, FST::RELATION('o', 2)), \
FST::NODE(1, FST::RELATION('n', 3)), \
FST::NODE(1, FST::RELATION('s', 4)), \
FST::NODE(1, FST::RELATION('o', 5)), \
FST::NODE(1, FST::RELATION('l', 6)), \
FST::NODE(1, FST::RELATION('e', 7)), \
FST::NODE(1, FST::RELATION('P', 8)), \
FST::NODE(1, FST::RELATION('r', 9)), \
FST::NODE(1, FST::RELATION('i', 10)), \
FST::NODE(1, FST::RELATION('n', 11)), \
FST::NODE(1, FST::RELATION('t', 12)), \
FST::NODE())

#define FST_RETURN(string) FST::FST(string, LEXSEMA_RETURN, 7, \
FST::NODE(1, FST::RELATION('r', 1)), \
FST::NODE(1, FST::RELATION('e', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE(1, FST::RELATION('u', 4)), \
FST::NODE(1, FST::RELATION('r', 5)), \
FST::NODE(1, FST::RELATION('n', 6)), \
FST::NODE())

#define FST_PARAM(string) FST::FST(string, LEXSEMA_PARAM, 6, \
FST::NODE(1, FST::RELATION('p', 1)), \
FST::NODE(1, FST::RELATION('a', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE(1, FST::RELATION('a', 4)), \
FST::NODE(1, FST::RELATION('m', 5)), \
FST::NODE())

#define FST_REPEAT(string) FST::FST(string, LEXSEMA_REPEAT, 7, \
FST::NODE(1, FST::RELATION('r', 1)), \
FST::NODE(1, FST::RELATION('e', 2)), \
FST::NODE(1, FST::RELATION('p', 3)), \
FST::NODE(1, FST::RELATION('e', 4)), \
FST::NODE(1, FST::RELATION('a', 5)), \
FST::NODE(1, FST::RELATION('t', 6)), \
FST::NODE())

#define FST_COMMENT(string) FST::FST(string, LEXSEMA_COMMENT,2, \
FST::NODE(1, FST::RELATION('#', 1)), \
FST::NODE())

#define FST_PLUS(string) FST::FST(string, LEXSEMA_PLUS, 2, \
FST::NODE(1, FST::RELATION('+', 0)), \
FST::NODE())

#define FST_TIMES(string) FST::FST(string, LEXSEMA_TIMES, 2, \
FST::NODE(1, FST::RELATION('*', 0)), \
FST::NODE())

#define FST_DIVIDE(string) FST::FST(string, LEXSEMA_DIVIDE, 2, \
FST::NODE(1, FST::RELATION('/', 0)), \
FST::NODE())

#define FST_MODULE(string) FST::FST(string, LEXSEMA_MODULE, 2, \
FST::NODE(1, FST::RELATION('%', 0)), \
FST::NODE())

#define FST_MINUS(string) FST::FST(string, LEXSEMA_MINUS, 2, \
FST::NODE(1, FST::RELATION('-', 0)), \
FST::NODE())

#define FST_LITERAL_STR(string) FST::FST(string, LEXSEMA_LITERAL, 3, \
FST::NODE(1, FST::RELATION('\"', 1)), \
FST::NODE(145, \
FST::RELATION(' ', 1), \
FST::RELATION('a', 1), \
FST::RELATION('b', 1), \
FST::RELATION('c', 1), \
FST::RELATION('d', 1), \
FST::RELATION('e', 1), \
FST::RELATION('f', 1), \
FST::RELATION('g', 1), \
FST::RELATION('h', 1), \
FST::RELATION('i', 1), \
FST::RELATION('j', 1), \
FST::RELATION('k', 1), \
FST::RELATION('l', 1), \
FST::RELATION('m', 1), \
FST::RELATION('n', 1), \
FST::RELATION('o', 1), \
FST::RELATION('p', 1), \
FST::RELATION('q', 1), \
FST::RELATION('r', 1), \
FST::RELATION('s', 1), \
FST::RELATION('t', 1), \
FST::RELATION('u', 1), \
FST::RELATION('v', 1), \
FST::RELATION('w', 1), \
FST::RELATION('x', 1), \
FST::RELATION('y', 1), \
FST::RELATION('z', 1), \
FST::RELATION('A', 1), \
FST::RELATION('B', 1), \
FST::RELATION('C', 1), \
FST::RELATION('D', 1), \
FST::RELATION('E', 1), \
FST::RELATION('F', 1), \
FST::RELATION('G', 1), \
FST::RELATION('H', 1), \
FST::RELATION('I', 1), \
FST::RELATION('J', 1), \
FST::RELATION('K', 1), \
FST::RELATION('L', 1), \
FST::RELATION('M', 1), \
FST::RELATION('N', 1), \
FST::RELATION('O', 1), \
FST::RELATION('P', 1), \
FST::RELATION('Q', 1), \
FST::RELATION('R', 1), \
FST::RELATION('S', 1), \
FST::RELATION('T', 1), \
FST::RELATION('U', 1), \
FST::RELATION('V', 1), \
FST::RELATION('W', 1), \
FST::RELATION('X', 1), \
FST::RELATION('Y', 1), \
FST::RELATION('Z', 1), \
FST::RELATION('0', 1), \
FST::RELATION('1', 1), \
FST::RELATION('2', 1), \
FST::RELATION('3', 1), \
FST::RELATION('4', 1), \
FST::RELATION('5', 1), \
FST::RELATION('6', 1), \
FST::RELATION('7', 1), \
FST::RELATION('8', 1), \
FST::RELATION('9', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('�', 1), \
FST::RELATION('=', 1), \
FST::RELATION('+', 1), \
FST::RELATION('-', 1), \
FST::RELATION('*', 1), \
FST::RELATION('/', 1), \
FST::RELATION('(', 1), \
FST::RELATION(')', 1), \
FST::RELATION('{', 1), \
FST::RELATION('}', 1), \
FST::RELATION(';', 1), \
FST::RELATION(':', 1), \
FST::RELATION(',', 1), \
FST::RELATION('?', 1), \
FST::RELATION('!', 1), \
FST::RELATION('_', 1), \
FST::RELATION('\"', 2)), \
FST::NODE())

#define FST_LITERAL_SH(string) FST::FST(string, LEXSEMA_LITERAL, 1, \
FST::NODE(10, \
FST::RELATION('0', 0), \
FST::RELATION('1', 0), \
FST::RELATION('2', 0), \
FST::RELATION('3', 0), \
FST::RELATION('4', 0), \
FST::RELATION('5', 0), \
FST::RELATION('6', 0), \
FST::RELATION('7', 0), \
FST::RELATION('8', 0), \
FST::RELATION('9', 0)), \
FST::NODE())

#define FST_LITERAL_MINUS_SH(string) FST::FST(string, LEXSEMA_LITERAL, 3, \
FST::NODE(1, FST::RELATION('-', 1)), \
FST::NODE(10, \
FST::RELATION('0', 2), \
FST::RELATION('1', 2), \
FST::RELATION('2', 2), \
FST::RELATION('3', 2), \
FST::RELATION('4', 2), \
FST::RELATION('5', 2), \
FST::RELATION('6', 2), \
FST::RELATION('7', 2), \
FST::RELATION('8', 2), \
FST::RELATION('9', 2)), \
FST::NODE(10, \
FST::RELATION('0', 2), \
FST::RELATION('1', 2), \
FST::RELATION('2', 2), \
FST::RELATION('3', 2), \
FST::RELATION('4', 2), \
FST::RELATION('5', 2), \
FST::RELATION('6', 2), \
FST::RELATION('7', 2), \
FST::RELATION('8', 2), \
FST::RELATION('9', 2)), \
FST::NODE())

#define FST_ID(string) FST::FST(string, LEXSEMA_ID, 1, \
FST::NODE(53, \
FST::RELATION('A', 0), \
FST::RELATION('B', 0), \
FST::RELATION('C', 0), \
FST::RELATION('D', 0), \
FST::RELATION('E', 0), \
FST::RELATION('F', 0), \
FST::RELATION('G', 0), \
FST::RELATION('H', 0), \
FST::RELATION('I', 0), \
FST::RELATION('J', 0), \
FST::RELATION('K', 0), \
FST::RELATION('L', 0), \
FST::RELATION('M', 0), \
FST::RELATION('N', 0), \
FST::RELATION('O', 0), \
FST::RELATION('P', 0), \
FST::RELATION('Q', 0), \
FST::RELATION('R', 0), \
FST::RELATION('S', 0), \
FST::RELATION('T', 0), \
FST::RELATION('U', 0), \
FST::RELATION('V', 0), \
FST::RELATION('W', 0), \
FST::RELATION('X', 0), \
FST::RELATION('Y', 0), \
FST::RELATION('Z', 0), \
FST::RELATION('a', 0), \
FST::RELATION('b', 0), \
FST::RELATION('c', 0), \
FST::RELATION('d', 0), \
FST::RELATION('e', 0), \
FST::RELATION('f', 0), \
FST::RELATION('g', 0), \
FST::RELATION('h', 0), \
FST::RELATION('i', 0), \
FST::RELATION('j', 0), \
FST::RELATION('k', 0), \
FST::RELATION('l', 0), \
FST::RELATION('m', 0), \
FST::RELATION('n', 0), \
FST::RELATION('o', 0), \
FST::RELATION('p', 0), \
FST::RELATION('q', 0), \
FST::RELATION('r', 0), \
FST::RELATION('s', 0), \
FST::RELATION('t', 0), \
FST::RELATION('u', 0), \
FST::RELATION('v', 0), \
FST::RELATION('w', 0), \
FST::RELATION('x', 0), \
FST::RELATION('y', 0), \
FST::RELATION('z', 0), \
FST::RELATION('_', 0)), \
FST::NODE())

#define FST_LITERAL_SH16(string) FST::FST(string, LEXSEMA_LITERAL, 3, \
FST::NODE(1, FST::RELATION('h', 1)), \
FST::NODE(22, \
FST::RELATION('0', 2), \
FST::RELATION('1', 2), \
FST::RELATION('2', 2), \
FST::RELATION('3', 2), \
FST::RELATION('4', 2), \
FST::RELATION('5', 2), \
FST::RELATION('6', 2), \
FST::RELATION('7', 2), \
FST::RELATION('8', 2), \
FST::RELATION('9', 2), \
FST::RELATION('A', 2), \
FST::RELATION('B', 2), \
FST::RELATION('C', 2), \
FST::RELATION('D', 2), \
FST::RELATION('E', 2), \
FST::RELATION('F', 2), \
FST::RELATION('a', 2), \
FST::RELATION('b', 2), \
FST::RELATION('c', 2), \
FST::RELATION('d', 2), \
FST::RELATION('e', 2), \
FST::RELATION('f', 2)), \
FST::NODE(22, \
FST::RELATION('0', 2), \
FST::RELATION('1', 2), \
FST::RELATION('2', 2), \
FST::RELATION('3', 2), \
FST::RELATION('4', 2), \
FST::RELATION('5', 2), \
FST::RELATION('6', 2), \
FST::RELATION('7', 2), \
FST::RELATION('8', 2), \
FST::RELATION('9', 2), \
FST::RELATION('A', 2), \
FST::RELATION('B', 2), \
FST::RELATION('C', 2), \
FST::RELATION('D', 2), \
FST::RELATION('E', 2), \
FST::RELATION('F', 2), \
FST::RELATION('a', 2), \
FST::RELATION('b', 2), \
FST::RELATION('c', 2), \
FST::RELATION('d', 2), \
FST::RELATION('e', 2), \
FST::RELATION('f', 2)), \
FST::NODE())

#define FST_LITERAL_M_SH16(string) FST::FST(string, LEXSEMA_LITERAL, 4, \
FST::NODE(1, FST::RELATION('~', 1)), \
FST::NODE(1, FST::RELATION('h', 2)), \
FST::NODE(22, \
FST::RELATION('0', 3), \
FST::RELATION('1', 3), \
FST::RELATION('2', 3), \
FST::RELATION('3', 3), \
FST::RELATION('4', 3), \
FST::RELATION('5', 3), \
FST::RELATION('6', 3), \
FST::RELATION('7', 3), \
FST::RELATION('8', 3), \
FST::RELATION('9', 3), \
FST::RELATION('A', 3), \
FST::RELATION('B', 3), \
FST::RELATION('C', 3), \
FST::RELATION('D', 3), \
FST::RELATION('E', 3), \
FST::RELATION('F', 3), \
FST::RELATION('a', 3), \
FST::RELATION('b', 3), \
FST::RELATION('c', 3), \
FST::RELATION('d', 3), \
FST::RELATION('e', 3), \
FST::RELATION('f', 3)), \
FST::NODE(22, \
FST::RELATION('0', 2), \
FST::RELATION('1', 2), \
FST::RELATION('2', 2), \
FST::RELATION('3', 2), \
FST::RELATION('4', 2), \
FST::RELATION('5', 2), \
FST::RELATION('6', 2), \
FST::RELATION('7', 2), \
FST::RELATION('8', 2), \
FST::RELATION('9', 2), \
FST::RELATION('A', 2), \
FST::RELATION('B', 2), \
FST::RELATION('C', 2), \
FST::RELATION('D', 2), \
FST::RELATION('E', 2), \
FST::RELATION('F', 2), \
FST::RELATION('a', 2), \
FST::RELATION('b', 2), \
FST::RELATION('c', 2), \
FST::RELATION('d', 2), \
FST::RELATION('e', 2), \
FST::RELATION('f', 2)), \
FST::NODE())

#define FST_LITERAL_SH2(string) FST::FST(string, LEXSEMA_LITERAL, 3, \
FST::NODE(1, FST::RELATION('b', 1)), \
FST::NODE(2, \
FST::RELATION('0', 2), \
FST::RELATION('1', 2)), \
FST::NODE(2, \
FST::RELATION('0', 2), \
FST::RELATION('1', 2)), \
FST::NODE())

#define FST_LITERAL_M_SH2(string) FST::FST(string, LEXSEMA_LITERAL, 4, \
FST::NODE(1, FST::RELATION('~', 1)), \
FST::NODE(1, FST::RELATION('b', 2)), \
FST::NODE(2, \
FST::RELATION('0', 3), \
FST::RELATION('1', 3)), \
FST::NODE(2, \
FST::RELATION('0', 3), \
FST::RELATION('1', 3)), \
FST::NODE())
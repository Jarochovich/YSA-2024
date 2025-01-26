#pragma once

#define LEXEMA_FIXSIZE	1			// фиксированный размер лексемы
#define	LT_MAXSIZE		4096		// максимальное количество строк в таблице лексем	
#define	LT_TI_NULLXDX	-1			// нет элемента таблицы идентификаторов	
#define	LT_V_NULL		'?'			// неопределен 


#define	LEXSEMA_SHORT		't'			// лексема для short
#define	LEXSEMA_STR			't'			// лексема для str
#define	LEXSEMA_ID			'i' 		// лексема для идентификатора
#define	LEXSEMA_LITERAL		'l'			// лексема для литерала
#define	LEXSEMA_FUNCTION	'f'			// лексема для function
#define	LEXSEMA_PARAM		'p'			// лексема для param
#define	LEXSEMA_VAR			'v'			// лексема для var
#define	LEXSEMA_REPEAT		'~'			// лексема для repeat
#define	LEXSEMA_RETURN		'r'			// лексема для return
#define	LEXSEMA_CP			'c'			// лексема для consolePrint
#define	LEXSEMA_MAIN		'm'			// лексема для main
#define	LEXSEMA_SEMICOLON	';'			// лексема для ;
#define	LEXSEMA_COMMA		','			// лексема для ,
#define	LEXSEMA_LEFTBRACE	'{'			// лексема для {
#define	LEXSEMA_RIGHTBRACE	'}'			// лексема для }
#define	LEXSEMA_LEFTHESIS	'('			// лексема для (
#define	LEXSEMA_RIGHTHESIS	')'			// лексема для )
#define LEXSEMA_PLUS		'+'			//лексема для +
#define LEXSEMA_MINUS		'-'			//лексема для -
#define LEXSEMA_TIMES		'*'			//лексема для *
#define LEXSEMA_DIVIDE		'/'			//лексема для /
#define LEXSEMA_MODULE		'%'			//лексема для %
#define	LEXSEMA_EQUAL		'='			// лексема для =
#define	LEXSEMA_MORE		'>'			// лексема для >
#define	LEXSEMA_LESS		'<'			// лексема для <
#define	LEXSEMA_COMPARE		'&'			// лексема для ==
#define	LEXSEMA_NOTEQUALS	'^'			// лексема для ==
#define LEXSEMA_COMMENT		'#'			// лексема для комментариев

#define PARM_LEX_DEFAULT_LOCATION	L"..\\YSA-2024\\Tables\\"	
#define PARM_LEX_DEFAULT_EXT		L".lex.txt" //для файла с итогом лексического анализa (таблица лексем)

namespace LT							// таблица лексем
{
	struct Entry						// строка таблицы лексем
	{
		char lexema;					// лексема
		char sign;						// знак лексемы v или LT_V_NULL
		int sn;							// номер строки в исходном тексте
		int tn;							// номер токена в строке
		int idxTI;						// индекс в таблице идентификаторов или LT_TI_NULLIDX

		Entry(char lexema, int sn, int tn, int idxTI);		// для идентификаторов
		Entry(char lexema, char sign, int sn, int tn);		// для операторов
		Entry(char lexema, int sn, int tn);					// остальные лексемы
		Entry(char lexema);
	};

	struct LexTable						// экземпляр таблицы лексем
	{
		int maxsize;					// емкость таблицы лексем < LT_MAXSIZE
		int current_size;				// текущий размер таблицы лексем < maxsize
		Entry** table;					// массив указателей на строки таблицы лексем

		LexTable();
		LexTable(int size);			// создать таблицу лексем
	};

	void Add(LexTable& lextable, Entry* entry);						// добавление лексем
	Entry GetEntry(LexTable& lextable, int n);						// получить строку таблицы лексем
	void PrintLexTable(LexTable& lextable, const wchar_t* in);		// вывод лексем в файл
	void Delete(LexTable& lextable);								// удалить таблицу лексем (освободить память)
}
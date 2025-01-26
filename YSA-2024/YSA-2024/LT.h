#pragma once

#define LEXEMA_FIXSIZE	1			// ������������� ������ �������
#define	LT_MAXSIZE		4096		// ������������ ���������� ����� � ������� ������	
#define	LT_TI_NULLXDX	-1			// ��� �������� ������� ���������������	
#define	LT_V_NULL		'?'			// ����������� 


#define	LEXSEMA_SHORT		't'			// ������� ��� short
#define	LEXSEMA_STR			't'			// ������� ��� str
#define	LEXSEMA_ID			'i' 		// ������� ��� ��������������
#define	LEXSEMA_LITERAL		'l'			// ������� ��� ��������
#define	LEXSEMA_FUNCTION	'f'			// ������� ��� function
#define	LEXSEMA_PARAM		'p'			// ������� ��� param
#define	LEXSEMA_VAR			'v'			// ������� ��� var
#define	LEXSEMA_REPEAT		'~'			// ������� ��� repeat
#define	LEXSEMA_RETURN		'r'			// ������� ��� return
#define	LEXSEMA_CP			'c'			// ������� ��� consolePrint
#define	LEXSEMA_MAIN		'm'			// ������� ��� main
#define	LEXSEMA_SEMICOLON	';'			// ������� ��� ;
#define	LEXSEMA_COMMA		','			// ������� ��� ,
#define	LEXSEMA_LEFTBRACE	'{'			// ������� ��� {
#define	LEXSEMA_RIGHTBRACE	'}'			// ������� ��� }
#define	LEXSEMA_LEFTHESIS	'('			// ������� ��� (
#define	LEXSEMA_RIGHTHESIS	')'			// ������� ��� )
#define LEXSEMA_PLUS		'+'			//������� ��� +
#define LEXSEMA_MINUS		'-'			//������� ��� -
#define LEXSEMA_TIMES		'*'			//������� ��� *
#define LEXSEMA_DIVIDE		'/'			//������� ��� /
#define LEXSEMA_MODULE		'%'			//������� ��� %
#define	LEXSEMA_EQUAL		'='			// ������� ��� =
#define	LEXSEMA_MORE		'>'			// ������� ��� >
#define	LEXSEMA_LESS		'<'			// ������� ��� <
#define	LEXSEMA_COMPARE		'&'			// ������� ��� ==
#define	LEXSEMA_NOTEQUALS	'^'			// ������� ��� ==
#define LEXSEMA_COMMENT		'#'			// ������� ��� ������������

#define PARM_LEX_DEFAULT_LOCATION	L"..\\YSA-2024\\Tables\\"	
#define PARM_LEX_DEFAULT_EXT		L".lex.txt" //��� ����� � ������ ������������ ������a (������� ������)

namespace LT							// ������� ������
{
	struct Entry						// ������ ������� ������
	{
		char lexema;					// �������
		char sign;						// ���� ������� v ��� LT_V_NULL
		int sn;							// ����� ������ � �������� ������
		int tn;							// ����� ������ � ������
		int idxTI;						// ������ � ������� ��������������� ��� LT_TI_NULLIDX

		Entry(char lexema, int sn, int tn, int idxTI);		// ��� ���������������
		Entry(char lexema, char sign, int sn, int tn);		// ��� ����������
		Entry(char lexema, int sn, int tn);					// ��������� �������
		Entry(char lexema);
	};

	struct LexTable						// ��������� ������� ������
	{
		int maxsize;					// ������� ������� ������ < LT_MAXSIZE
		int current_size;				// ������� ������ ������� ������ < maxsize
		Entry** table;					// ������ ���������� �� ������ ������� ������

		LexTable();
		LexTable(int size);			// ������� ������� ������
	};

	void Add(LexTable& lextable, Entry* entry);						// ���������� ������
	Entry GetEntry(LexTable& lextable, int n);						// �������� ������ ������� ������
	void PrintLexTable(LexTable& lextable, const wchar_t* in);		// ����� ������ � ����
	void Delete(LexTable& lextable);								// ������� ������� ������ (���������� ������)
}
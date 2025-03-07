#include "stdafx.h"
#include "FST.h"
#include "LT.h"

namespace FST
{
	RELATION::RELATION(char c = 0x00, short ns = NULL)
	{
		symbol = c;
		nnode = ns;
	};

	NODE::NODE()								// �� ���������
	{
		n_relation = 0;
		RELATION* relations = NULL;
	};

	NODE::NODE(short n, RELATION rel, ...)		// � �����������
	{
		n_relation = n;
		RELATION* ptr = &rel;
		relations = new RELATION[n];

		for (short i = 0; i < n; i++)
		{
			relations[i] = ptr[i];
		}
	};

	FST::FST(const char* s, const char lex, short ns, NODE n, ...)
	{
		lexema = lex;
		string = s;
		nstates = ns;
		nodes = new NODE[ns];
		NODE* ptr = &n;

		for (int k = 0; k < ns; k++)
		{
			nodes[k] = ptr[k];
		}

		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short) * nstates);
		rstates[0] = 0;
		position = -1;
	};

	bool step(FST& fst, short*& rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);			// ����� ��������
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					}
				}
		}
		return rc;
	};

	bool execute(FST& fst)
	{
		short* rstates = new short[fst.nstates];
		memset(rstates, 0xff, sizeof(short) * fst.nstates);
		short lstring = strlen(fst.string);
		bool rc = true;

		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates);
		}

		delete[] rstates;

		switch (fst.lexema) 
		{
			case LEXSEMA_PLUS:
			case LEXSEMA_MINUS:
			case LEXSEMA_TIMES:
			case LEXSEMA_DIVIDE:
			case LEXSEMA_MODULE:
				return (rc ? (fst.rstates[fst.nstates - 2] == lstring) : rc);
		}
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	}
}




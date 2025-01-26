#include "stdafx.h"
#include "PolishNotation.h"
#include <stack>
#include <queue>

using namespace std;

namespace PN
{
	bool polishNotation(int lextable_pos, LT::LexTable& lextable, IT::IdTable& idtable)
	{
		stack<LT::Entry*> stk;    // ������� ���� ��� �������� ��������� ��������
		queue<LT::Entry*> result;
		bool function = false;
		int quantityParm = 0;
		int i = ++lextable_pos;

		for (; lextable.table[i]->lexema != LEXSEMA_SEMICOLON && (lextable.table[i]->lexema != LEXSEMA_RIGHTHESIS || !stk.empty()); i++)
		{
			switch (lextable.table[i]->lexema)
			{
			case LEXSEMA_ID:            // ��������
			case LEXSEMA_LITERAL:
				if (idtable.table[lextable.table[i]->idxTI]->idtype == IT::IDTYPE::F)
				{
					quantityParm = 0;
					function = true;
					result.push(lextable.table[i]);
					break;
				}
				if (function && !quantityParm)
					quantityParm++;

				result.push(lextable.table[i]);
				break;

			case LEXSEMA_PLUS:
			case LEXSEMA_MINUS:
			case LEXSEMA_TIMES:
			case LEXSEMA_DIVIDE:
			case LEXSEMA_MODULE:

				if (stk.empty() || stk.top()->lexema == LEXSEMA_LEFTHESIS)
					stk.push(lextable.table[i]);
				else
				{
					int prioritet = priority(lextable.table[i]->sign);
					if (priority(stk.top()->sign) >= prioritet)
					{
						result.push(stk.top());

						stk.pop();
					}
					stk.push(lextable.table[i]);
				}
				break;

			case LEXSEMA_LEFTHESIS:
				stk.push(lextable.table[i]);
				break;

			case LEXSEMA_RIGHTHESIS:
				while (stk.top()->lexema != LEXSEMA_LEFTHESIS)
				{
					result.push(stk.top());

					stk.pop();
				}
				stk.pop();

				if (function)
				{
					result.push(new LT::Entry('@'));
					result.push(new LT::Entry('0' + quantityParm));
					function = false;
				}
				break;

			case LEXSEMA_COMMA:
				if (function)
					quantityParm++;
				while (stk.top()->lexema != LEXSEMA_LEFTHESIS)
				{
					result.push(stk.top());

					stk.pop();
				}
				break;
			case LEXSEMA_MORE:
			case LEXSEMA_LESS:
				result.push(lextable.table[i]);
				break;
			}

		}
		while (!stk.empty())
		{
			result.push(stk.top());
			stk.pop();
		}
		for (int j = lextable_pos; j < i; j++)
		{
			if (!result.empty())
			{
				lextable.table[j] = result.front();
				lextable.table[j]->sn = lextable.table[j - 1]->sn;
				lextable.table[j]->tn = lextable.table[j - 1]->tn + 1;
				result.pop();
			}
			else
			{
				lextable.table[j] = new LT::Entry('#', lextable.table[j]->sn = lextable.table[j - 1]->sn, lextable.table[j]->tn = lextable.table[j - 1]->tn + 1);
			}
		}

		return true;
	}

	int priority(char v)
	{
		switch (v)
		{
			case '(':
			case ')': return 1;
			case ',': return 2;
			case '+':
			case '-': return 3;
			case '*':
			case '/':
			case '%': return 4;
		}
	}

	int findExpression(LT::LexTable& lextable)
	{
		for (static int i = 0; i < lextable.current_size; i++)
		{
			if (lextable.table[i]->lexema == LEXSEMA_EQUAL)
				return ++i;
		}
		return 0;
	}
}
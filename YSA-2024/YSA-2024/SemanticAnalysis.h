#pragma once
#include "LT.h"
#include "IT.h"
#include "Log.h"

namespace SM
{
	void semAnaliz(LT::LexTable& lextable, IT::IdTable& idtable);
	void CheckAllowedValue(Log::LOG log, LT::LexTable lextable, IT::IdTable idtable);
};
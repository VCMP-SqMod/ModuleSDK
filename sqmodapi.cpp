// ////////////////////////////////////////////////////////////////////////////////////////////////
#include "sqmodapi.h"

// ------------------------------------------------------------------------------------------------
static SQMODAPI g_API{};

// ------------------------------------------------------------------------------------------------
//primitive functions
HSQUIRRELVM SqMod_GetSquirrelVM(void) {
	g_API.GetSquirrelVM();
}
//logging utilities
void SqMod_LogDbg(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogDbg(fmt, args);
    va_end(args);
}
void SqMod_LogUsr(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogUsr(fmt, args);
    va_end(args);
}
void SqMod_LogScs(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogScs(fmt, args);
    va_end(args);
}
void SqMod_LogInf(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogInf(fmt, args);
    va_end(args);
}
void SqMod_LogWrn(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogWrn(fmt, args);
    va_end(args);
}
void SqMod_LogErr(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogErr(fmt, args);
    va_end(args);
}
void SqMod_LogFtl(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogFtl(fmt, args);
    va_end(args);
}
void SqMod_LogSDbg(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogSDbg(fmt, args);
    va_end(args);
}
void SqMod_LogSUsr(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogSUsr(fmt, args);
    va_end(args);
}
void SqMod_LogSScs(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogSScs(fmt, args);
    va_end(args);
}
void SqMod_LogSInf(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogSInf(fmt, args);
    va_end(args);
}
void SqMod_LogSWrn(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogSWrn(fmt, args);
    va_end(args);
}
void SqMod_LogSErr(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogSErr(fmt, args);
    va_end(args);
}
void SqMod_LogSFtl(const SQChar * fmt, ...) {
    va_list args;
    va_start(args, fmt);
	g_API.LogSFtl(fmt, args);
    va_end(args);
}
void SqMod_LogDbgV(const SQChar * fmt, va_list vlist) {
	g_API.LogDbgV(fmt, vlist);
}
void SqMod_LogUsrV(const SQChar * fmt, va_list vlist) {
	g_API.LogUsrV(fmt, vlist);
}
void SqMod_LogScsV(const SQChar * fmt, va_list vlist) {
	g_API.LogScsV(fmt, vlist);
}
void SqMod_LogInfV(const SQChar * fmt, va_list vlist) {
	g_API.LogInfV(fmt, vlist);
}
void SqMod_LogWrnV(const SQChar * fmt, va_list vlist) {
	g_API.LogWrnV(fmt, vlist);
}
void SqMod_LogErrV(const SQChar * fmt, va_list vlist) {
	g_API.LogErrV(fmt, vlist);
}
void SqMod_LogFtlV(const SQChar * fmt, va_list vlist) {
	g_API.LogFtlV(fmt, vlist);
}
void SqMod_LogSDbgV(const SQChar * fmt, va_list vlist) {
	g_API.LogSDbgV(fmt, vlist);
}
void SqMod_LogSUsrV(const SQChar * fmt, va_list vlist) {
	g_API.LogSUsrV(fmt, vlist);
}
void SqMod_LogSScsV(const SQChar * fmt, va_list vlist) {
	g_API.LogSScsV(fmt, vlist);
}
void SqMod_LogSInfV(const SQChar * fmt, va_list vlist) {
	g_API.LogSInfV(fmt, vlist);
}
void SqMod_LogSWrnV(const SQChar * fmt, va_list vlist) {
	g_API.LogSWrnV(fmt, vlist);
}
void SqMod_LogSErrV(const SQChar * fmt, va_list vlist) {
	g_API.LogSErrV(fmt, vlist);
}
void SqMod_LogSFtlV(const SQChar * fmt, va_list vlist) {
	g_API.LogSFtlV(fmt, vlist);
}

//script loading
SQRESULT SqMod_LoadScript(const SQChar * filepath, SQBool delay) {
	g_API.LoadScript(filepath, delay);
}

// ------------------------------------------------------------------------------------------------
int sqmod_api_expand(HSQMODAPI sqmodapi)
{
    if (!sqmodapi)
    {
        return 0;
    }

    // Copy API entries
    memcpy(&g_API, sqmodapi, sizeof(SQMODAPI));

    return 1;
}

// ------------------------------------------------------------------------------------------------
void sqmod_api_collapse()
{
	memset(&g_API, 0, sizeof(SQMODAPI));
}

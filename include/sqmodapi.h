//
// SqModule: API used to communicate with and register squirrel modules
//

//
// Copyright (c) 2016 Sandu Liviu Catalin (aka. S.L.C)
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source
//  distribution.
//

#if !defined(_SQ_MOD_H_)
#define _SQ_MOD_H_

#include <sqlibapi.h>
#include <vcmp.h>

#ifdef __cplusplus
extern "C" {
#endif

	#if defined(_MSC_VER)
	    #define SQMOD_API_EXPORT    extern "C" __declspec(dllexport)
	#elif defined(__GNUC__)
	    #define SQMOD_API_EXPORT    extern "C"
	#else
	    #define SQMOD_API_EXPORT    extern "C"
	#endif

	#define SQMOD_HOST_NAME         "SqModHost"
	#define SQMOD_INITIALIZE_CMD    0xDABBAD00
	#define SQMOD_LOAD_CMD          0xDEADBABE
	#define SQMOD_TERMINATE_CMD     0xDEADC0DE
	#define SQMOD_CLOSING_CMD       0xBAAAAAAD
	#define SQMOD_RELEASED_CMD      0xDEADBEAF
	#define SQMOD_API_VER           1

	/**< 64 bits integer types */
	#if defined(_MSC_VER)
	    typedef __int64                 SqInt64;
	    typedef unsigned __int64        SqUint64;
	#else
	    typedef long long               SqInt64;
	    typedef unsigned long long      SqUint64;
	#endif

    //primitive functions
    typedef HSQUIRRELVM     (*SqModAPI_GetSquirrelVM) (void);
    //logging utilities
    typedef void            (*SqModAPI_LogMessage) (const SQChar * fmt, ...);
    typedef void            (*SqModAPI_LogMessageV) (const SQChar * fmt, va_list vlist);
    //script loading
    typedef SQRESULT        (*SqModAPI_LoadScript) (const SQChar * filepath, SQBool delay);

    /* --------------------------------------------------------------------------------------------
     * Allows modules to interface with the plug-in API without linking of any sorts
    */
    typedef struct
    {
        //primitive functions
        SqModAPI_GetSquirrelVM                      GetSquirrelVM;
        //logging utilities
        SqModAPI_LogMessage                         LogDbg;
        SqModAPI_LogMessage                         LogUsr;
        SqModAPI_LogMessage                         LogScs;
        SqModAPI_LogMessage                         LogInf;
        SqModAPI_LogMessage                         LogWrn;
        SqModAPI_LogMessage                         LogErr;
        SqModAPI_LogMessage                         LogFtl;
        SqModAPI_LogMessage                         LogSDbg;
        SqModAPI_LogMessage                         LogSUsr;
        SqModAPI_LogMessage                         LogSScs;
        SqModAPI_LogMessage                         LogSInf;
        SqModAPI_LogMessage                         LogSWrn;
        SqModAPI_LogMessage                         LogSErr;
        SqModAPI_LogMessage                         LogSFtl;
        SqModAPI_LogMessageV                        LogDbgV;
        SqModAPI_LogMessageV                        LogUsrV;
        SqModAPI_LogMessageV                        LogScsV;
        SqModAPI_LogMessageV                        LogInfV;
        SqModAPI_LogMessageV                        LogWrnV;
        SqModAPI_LogMessageV                        LogErrV;
        SqModAPI_LogMessageV                        LogFtlV;
        SqModAPI_LogMessageV                        LogSDbgV;
        SqModAPI_LogMessageV                        LogSUsrV;
        SqModAPI_LogMessageV                        LogSScsV;
        SqModAPI_LogMessageV                        LogSInfV;
        SqModAPI_LogMessageV                        LogSWrnV;
        SqModAPI_LogMessageV                        LogSErrV;
        SqModAPI_LogMessageV                        LogSFtlV;
        //script loading
        SqModAPI_LoadScript                         LoadScript;
    } sq_modapi, SQMODAPI, *HSQMODAPI;

    /* --------------------------------------------------------------------------------------------
     * Plugin API
    */
    //primitive functions
    SQUIRREL_API HSQUIRRELVM SqMod_GetSquirrelVM(void);
    //logging utilities
    SQUIRREL_API void SqMod_LogDbg(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogUsr(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogScs(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogInf(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogWrn(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogErr(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogFtl(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogSDbg(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogSUsr(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogSScs(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogSInf(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogSWrn(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogSErr(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogSFtl(const SQChar * fmt, ...);
    SQUIRREL_API void SqMod_LogDbgV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogUsrV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogScsV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogInfV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogWrnV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogErrV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogFtlV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogSDbgV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogSUsrV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogSScsV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogSInfV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogSWrnV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogSErrV(const SQChar * fmt, va_list vlist);
    SQUIRREL_API void SqMod_LogSFtlV(const SQChar * fmt, va_list vlist);
    //script loading
    SQUIRREL_API SQRESULT SqMod_LoadScript(const SQChar * filepath, SQBool delay);

    /* --------------------------------------------------------------------------------------------
     * The structure exported by the host plug-in to import the module and squirrel API.
    */
    typedef struct
    {
        unsigned int StructSize;
        //base functions
        int32_t (*PopulateModuleAPI) (HSQMODAPI api, size_t size);
        int32_t (*PopulateSquirrelAPI) (HSQLIBAPI api, size_t size);
    } sq_modexports, SQMODEXPORTS, *HSQMODEXPORTS;

    /* --------------------------------------------------------------------------------------------
     * Assign the functions from the specified API structure into the global functions.
    */
    SQUIRREL_API int sqmod_api_expand(HSQMODAPI sqmodapi);

    /* --------------------------------------------------------------------------------------------
     * Undo changes done by sqmod_api_expand.
    */
    SQUIRREL_API void sqmod_api_collapse();

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*_SQ_MOD_H_*/

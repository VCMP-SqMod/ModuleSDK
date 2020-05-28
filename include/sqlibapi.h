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

#if !defined(_SQ_PLUGIN_H_)
#define _SQ_PLUGIN_H_

#include <squirrelex.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

    //vm
    typedef HSQUIRRELVM (*SqLibAPI_open)(SQInteger initialstacksize);
    typedef HSQUIRRELVM (*SqLibAPI_newthread)(HSQUIRRELVM friendvm, SQInteger initialstacksize);
    typedef void (*SqLibAPI_seterrorhandler)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_close)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_setforeignptr)(HSQUIRRELVM v,SQUserPointer p);
    typedef SQUserPointer (*SqLibAPI_getforeignptr)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_setsharedforeignptr)(HSQUIRRELVM v,SQUserPointer p);
    typedef SQUserPointer (*SqLibAPI_getsharedforeignptr)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_setvmreleasehook)(HSQUIRRELVM v,SQRELEASEHOOK hook);
    typedef SQRELEASEHOOK (*SqLibAPI_getvmreleasehook)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_setsharedreleasehook)(HSQUIRRELVM v,SQRELEASEHOOK hook);
    typedef SQRELEASEHOOK (*SqLibAPI_getsharedreleasehook)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_setprintfunc)(HSQUIRRELVM v, SQPRINTFUNCTION printfunc,SQPRINTFUNCTION errfunc);
    typedef SQPRINTFUNCTION (*SqLibAPI_getprintfunc)(HSQUIRRELVM v);
    typedef SQPRINTFUNCTION (*SqLibAPI_geterrorfunc)(HSQUIRRELVM v);
    typedef SQRESULT (*SqLibAPI_suspendvm)(HSQUIRRELVM v);
    typedef SQRESULT (*SqLibAPI_wakeupvm)(HSQUIRRELVM v,SQBool resumedret,SQBool retval,SQBool raiseerror,SQBool throwerror);
    typedef SQInteger (*SqLibAPI_getvmstate)(HSQUIRRELVM v);
    typedef SQInteger (*SqLibAPI_getversion)();

    //compiler
    typedef SQRESULT (*SqLibAPI_compile)(HSQUIRRELVM v,SQLEXREADFUNC read,SQUserPointer p,const SQChar *sourcename,SQBool raiseerror);
    typedef SQRESULT (*SqLibAPI_compilebuffer)(HSQUIRRELVM v,const SQChar *s,SQInteger size,const SQChar *sourcename,SQBool raiseerror);
    typedef void (*SqLibAPI_enabledebuginfo)(HSQUIRRELVM v, SQBool enable);
    typedef void (*SqLibAPI_notifyallexceptions)(HSQUIRRELVM v, SQBool enable);
    typedef void (*SqLibAPI_setcompilererrorhandler)(HSQUIRRELVM v,SQCOMPILERERROR f);

    //stack operations
    typedef void (*SqLibAPI_push)(HSQUIRRELVM v,SQInteger idx);
    typedef void (*SqLibAPI_pop)(HSQUIRRELVM v,SQInteger nelemstopop);
    typedef void (*SqLibAPI_poptop)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_remove)(HSQUIRRELVM v,SQInteger idx);
    typedef SQInteger (*SqLibAPI_gettop)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_settop)(HSQUIRRELVM v,SQInteger newtop);
    typedef SQRESULT (*SqLibAPI_reservestack)(HSQUIRRELVM v,SQInteger nsize);
    typedef SQInteger (*SqLibAPI_cmp)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_move)(HSQUIRRELVM dest,HSQUIRRELVM src,SQInteger idx);

    //object creation handling
    typedef SQUserPointer (*SqLibAPI_newuserdata)(HSQUIRRELVM v,SQUnsignedInteger size);
    typedef void (*SqLibAPI_newtable)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_newtableex)(HSQUIRRELVM v,SQInteger initialcapacity);
    typedef void (*SqLibAPI_newarray)(HSQUIRRELVM v,SQInteger size);
    typedef void (*SqLibAPI_newclosure)(HSQUIRRELVM v,SQFUNCTION func,SQUnsignedInteger nfreevars);
    typedef SQRESULT (*SqLibAPI_setparamscheck)(HSQUIRRELVM v,SQInteger nparamscheck,const SQChar *typemask);
    typedef SQRESULT (*SqLibAPI_bindenv)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_setclosureroot)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_getclosureroot)(HSQUIRRELVM v,SQInteger idx);
    typedef void (*SqLibAPI_pushstring)(HSQUIRRELVM v,const SQChar *s,SQInteger len);
    typedef SQRESULT (*SqLibAPI_pushstringf)(HSQUIRRELVM v,const SQChar *s,...);
    typedef SQRESULT (*SqLibAPI_vpushstringf)(HSQUIRRELVM v,const SQChar *s,va_list l);
    typedef void (*SqLibAPI_pushfloat)(HSQUIRRELVM v,SQFloat f);
    typedef void (*SqLibAPI_pushinteger)(HSQUIRRELVM v,SQInteger n);
    typedef void (*SqLibAPI_pushbool)(HSQUIRRELVM v,SQBool b);
    typedef void (*SqLibAPI_pushuserpointer)(HSQUIRRELVM v,SQUserPointer p);
    typedef void (*SqLibAPI_pushnull)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_pushthread)(HSQUIRRELVM v, HSQUIRRELVM thread);
    typedef SQObjectType (*SqLibAPI_gettype)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_typeof)(HSQUIRRELVM v,SQInteger idx);
    typedef SQInteger (*SqLibAPI_getsize)(HSQUIRRELVM v,SQInteger idx);
    typedef SQHash (*SqLibAPI_gethash)(HSQUIRRELVM v, SQInteger idx);
    typedef SQRESULT (*SqLibAPI_getbase)(HSQUIRRELVM v,SQInteger idx);
    typedef SQBool (*SqLibAPI_instanceof)(HSQUIRRELVM v);
    typedef SQRESULT (*SqLibAPI_tostring)(HSQUIRRELVM v,SQInteger idx);
    typedef void (*SqLibAPI_tobool)(HSQUIRRELVM v, SQInteger idx, SQBool *b);
    typedef SQRESULT (*SqLibAPI_getstringandsize)(HSQUIRRELVM v,SQInteger idx,const SQChar **c,SQInteger *size);
    typedef SQRESULT (*SqLibAPI_getstring)(HSQUIRRELVM v,SQInteger idx,const SQChar **c);
    typedef SQRESULT (*SqLibAPI_getinteger)(HSQUIRRELVM v,SQInteger idx,SQInteger *i);
    typedef SQRESULT (*SqLibAPI_getfloat)(HSQUIRRELVM v,SQInteger idx,SQFloat *f);
    typedef SQRESULT (*SqLibAPI_getbool)(HSQUIRRELVM v,SQInteger idx,SQBool *b);
    typedef SQRESULT (*SqLibAPI_getthread)(HSQUIRRELVM v,SQInteger idx,HSQUIRRELVM *thread);
    typedef SQRESULT (*SqLibAPI_getuserpointer)(HSQUIRRELVM v,SQInteger idx,SQUserPointer *p);
    typedef SQRESULT (*SqLibAPI_getuserdata)(HSQUIRRELVM v,SQInteger idx,SQUserPointer *p,SQUserPointer *typetag);
    typedef SQRESULT (*SqLibAPI_settypetag)(HSQUIRRELVM v,SQInteger idx,SQUserPointer typetag);
    typedef SQRESULT (*SqLibAPI_gettypetag)(HSQUIRRELVM v,SQInteger idx,SQUserPointer *typetag);
    typedef void (*SqLibAPI_setreleasehook)(HSQUIRRELVM v,SQInteger idx,SQRELEASEHOOK hook);
    typedef SQRELEASEHOOK (*SqLibAPI_getreleasehook)(HSQUIRRELVM v,SQInteger idx);
    typedef SQChar* (*SqLibAPI_getscratchpad)(HSQUIRRELVM v,SQInteger minsize);
    typedef SQRESULT (*SqLibAPI_getfunctioninfo)(HSQUIRRELVM v,SQInteger level,SQFunctionInfo *fi);
    typedef SQRESULT (*SqLibAPI_getclosureinfo)(HSQUIRRELVM v,SQInteger idx,SQInteger *nparams,SQInteger *nfreevars);
    typedef SQRESULT (*SqLibAPI_getclosurename)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_setnativeclosurename)(HSQUIRRELVM v,SQInteger idx,const SQChar *name);
    typedef SQRESULT (*SqLibAPI_getnativeclosurepointer)(HSQUIRRELVM v,SQInteger idx,SQFUNCTION *f);
    typedef SQRESULT (*SqLibAPI_setinstanceup)(HSQUIRRELVM v, SQInteger idx, SQUserPointer p);
    typedef SQRESULT (*SqLibAPI_getinstanceup)(HSQUIRRELVM v, SQInteger idx, SQUserPointer *p,SQUserPointer typetag);
    typedef SQRESULT (*SqLibAPI_setclassudsize)(HSQUIRRELVM v, SQInteger idx, SQInteger udsize);
    typedef SQRESULT (*SqLibAPI_newclass)(HSQUIRRELVM v,SQBool hasbase);
    typedef SQRESULT (*SqLibAPI_createinstance)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_setattributes)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_getattributes)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_getclass)(HSQUIRRELVM v,SQInteger idx);
    typedef void (*SqLibAPI_weakref)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_getdefaultdelegate)(HSQUIRRELVM v,SQObjectType t);
    typedef SQRESULT (*SqLibAPI_getmemberhandle)(HSQUIRRELVM v,SQInteger idx,HSQMEMBERHANDLE *handle);
    typedef SQRESULT (*SqLibAPI_getbyhandle)(HSQUIRRELVM v,SQInteger idx,const HSQMEMBERHANDLE *handle);
    typedef SQRESULT (*SqLibAPI_setbyhandle)(HSQUIRRELVM v,SQInteger idx,const HSQMEMBERHANDLE *handle);

    //object manipulation
    typedef void (*SqLibAPI_pushroottable)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_pushregistrytable)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_pushconsttable)(HSQUIRRELVM v);
    typedef SQRESULT (*SqLibAPI_setroottable)(HSQUIRRELVM v);
    typedef SQRESULT (*SqLibAPI_setconsttable)(HSQUIRRELVM v);
    typedef SQRESULT (*SqLibAPI_newslot)(HSQUIRRELVM v, SQInteger idx, SQBool bstatic);
    typedef SQRESULT (*SqLibAPI_deleteslot)(HSQUIRRELVM v,SQInteger idx,SQBool pushval);
    typedef SQRESULT (*SqLibAPI_set)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_get)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_rawget)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_rawset)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_rawdeleteslot)(HSQUIRRELVM v,SQInteger idx,SQBool pushval);
    typedef SQRESULT (*SqLibAPI_newmember)(HSQUIRRELVM v,SQInteger idx,SQBool bstatic);
    typedef SQRESULT (*SqLibAPI_rawnewmember)(HSQUIRRELVM v,SQInteger idx,SQBool bstatic);
    typedef SQRESULT (*SqLibAPI_arrayappend)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_arraypop)(HSQUIRRELVM v,SQInteger idx,SQBool pushval);
    typedef SQRESULT (*SqLibAPI_arrayresize)(HSQUIRRELVM v,SQInteger idx,SQInteger newsize);
    typedef SQRESULT (*SqLibAPI_arrayreverse)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_arrayremove)(HSQUIRRELVM v,SQInteger idx,SQInteger itemidx);
    typedef SQRESULT (*SqLibAPI_arrayinsert)(HSQUIRRELVM v,SQInteger idx,SQInteger destpos);
    typedef SQRESULT (*SqLibAPI_setdelegate)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_getdelegate)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_clone)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_setfreevariable)(HSQUIRRELVM v,SQInteger idx,SQUnsignedInteger nval);
    typedef SQRESULT (*SqLibAPI_next)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_getweakrefval)(HSQUIRRELVM v,SQInteger idx);
    typedef SQRESULT (*SqLibAPI_clear)(HSQUIRRELVM v,SQInteger idx);

    //calls
    typedef SQRESULT (*SqLibAPI_call)(HSQUIRRELVM v,SQInteger params,SQBool retval,SQBool raiseerror);
    typedef SQRESULT (*SqLibAPI_resume)(HSQUIRRELVM v,SQBool retval,SQBool raiseerror);
    typedef const SQChar* (*SqLibAPI_getlocal)(HSQUIRRELVM v,SQUnsignedInteger level,SQUnsignedInteger idx);
    typedef SQRESULT (*SqLibAPI_getcallee)(HSQUIRRELVM v);
    typedef const SQChar* (*SqLibAPI_getfreevariable)(HSQUIRRELVM v,SQInteger idx,SQUnsignedInteger nval);
    typedef const SQChar* (*SqLibAPI_getonefreevariable)(HSQUIRRELVM v,SQUnsignedInteger nval);
    typedef SQRESULT (*SqLibAPI_throwerror)(HSQUIRRELVM v,const SQChar *err);
    typedef SQRESULT (*SqLibAPI_throwerrorf)(HSQUIRRELVM v,const SQChar *err,...);
    typedef SQRESULT (*SqLibAPI_throwobject)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_reseterror)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_getlasterror)(HSQUIRRELVM v);

    //raw object handling
    typedef SQRESULT (*SqLibAPI_getstackobj)(HSQUIRRELVM v,SQInteger idx,HSQOBJECT *po);
    typedef void (*SqLibAPI_pushobject)(HSQUIRRELVM v,HSQOBJECT obj);
    typedef void (*SqLibAPI_addref)(HSQUIRRELVM v,HSQOBJECT *po);
    typedef SQBool (*SqLibAPI_release)(HSQUIRRELVM v,HSQOBJECT *po);
    typedef SQUnsignedInteger (*SqLibAPI_getrefcount)(HSQUIRRELVM v,HSQOBJECT *po);
    typedef void (*SqLibAPI_resetobject)(HSQOBJECT *po);
    typedef const SQChar* (*SqLibAPI_objtostring)(const HSQOBJECT *o);
    typedef SQBool (*SqLibAPI_objtobool)(const HSQOBJECT *o);
    typedef SQInteger (*SqLibAPI_objtointeger)(const HSQOBJECT *o);
    typedef SQFloat (*SqLibAPI_objtofloat)(const HSQOBJECT *o);
    typedef SQUserPointer (*SqLibAPI_objtouserpointer)(const HSQOBJECT *o);
    typedef SQRESULT (*SqLibAPI_getobjtypetag)(const HSQOBJECT *o,SQUserPointer * typetag);
    typedef SQUnsignedInteger (*SqLibAPI_getvmrefcount)(HSQUIRRELVM v, const HSQOBJECT *po);


    //GC
    typedef SQInteger (*SqLibAPI_collectgarbage)(HSQUIRRELVM v);
    typedef SQRESULT (*SqLibAPI_resurrectunreachable)(HSQUIRRELVM v);

    //serialization
    typedef SQRESULT (*SqLibAPI_writeclosure)(HSQUIRRELVM vm,SQWRITEFUNC writef,SQUserPointer up);
    typedef SQRESULT (*SqLibAPI_readclosure)(HSQUIRRELVM vm,SQREADFUNC readf,SQUserPointer up);

    //mem allocation
    typedef void* (*SqLibAPI_malloc)(SQUnsignedInteger size);
    typedef void* (*SqLibAPI_realloc)(void* p,SQUnsignedInteger oldsize,SQUnsignedInteger newsize);
    typedef void (*SqLibAPI_free)(void *p,SQUnsignedInteger size);

    //debug
    typedef SQRESULT (*SqLibAPI_stackinfos)(HSQUIRRELVM v,SQInteger level,SQStackInfos *si);
    typedef void (*SqLibAPI_setdebughook)(HSQUIRRELVM v);
    typedef void (*SqLibAPI_setnativedebughook)(HSQUIRRELVM v,SQDEBUGHOOK hook);

    //compiler helpers
    typedef SQRESULT (*SqLibAPI_loadfile)(HSQUIRRELVM v,const SQChar *filename,SQBool printerror);
    typedef SQRESULT (*SqLibAPI_dofile)(HSQUIRRELVM v,const SQChar *filename,SQBool retval,SQBool printerror);
    typedef SQRESULT (*SqLibAPI_writeclosuretofile)(HSQUIRRELVM v,const SQChar *filename);

    //blob
    typedef SQUserPointer (*SqLibAPI_createblob)(HSQUIRRELVM v, SQInteger size);
    typedef SQRESULT (*SqLibAPI_getblob)(HSQUIRRELVM v,SQInteger idx,SQUserPointer *ptr);
    typedef SQInteger (*SqLibAPI_getblobsize)(HSQUIRRELVM v,SQInteger idx);

    //string
    typedef SQRESULT (*SqLibAPI_format)(HSQUIRRELVM v,SQInteger nformatstringidx,SQInteger *outlen,SQChar **output);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @cond DEV
    /// Allows modules to interface with Squirrel's C api without linking to the squirrel library.
    /// If new functions are added to the Squirrel API, they should be added here too.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef struct
    {
        //vm
        SqLibAPI_open                               open;
        SqLibAPI_newthread                          newthread;
        SqLibAPI_seterrorhandler                    seterrorhandler;
        SqLibAPI_close                              close;
        SqLibAPI_setforeignptr                      setforeignptr;
        SqLibAPI_getforeignptr                      getforeignptr;
        SqLibAPI_setsharedforeignptr                setsharedforeignptr;
        SqLibAPI_getsharedforeignptr                getsharedforeignptr;
        SqLibAPI_setvmreleasehook                   setvmreleasehook;
        SqLibAPI_getvmreleasehook                   getvmreleasehook;
        SqLibAPI_setsharedreleasehook               setsharedreleasehook;
        SqLibAPI_getsharedreleasehook               getsharedreleasehook;
        SqLibAPI_setprintfunc                       setprintfunc;
        SqLibAPI_getprintfunc                       getprintfunc;
        SqLibAPI_geterrorfunc                       geterrorfunc;
        SqLibAPI_suspendvm                          suspendvm;
        SqLibAPI_wakeupvm                           wakeupvm;
        SqLibAPI_getvmstate                         getvmstate;
        SqLibAPI_getversion                         getversion;

        //compiler
        SqLibAPI_compile                            compile;
        SqLibAPI_compilebuffer                      compilebuffer;
        SqLibAPI_enabledebuginfo                    enabledebuginfo;
        SqLibAPI_notifyallexceptions                notifyallexceptions;
        SqLibAPI_setcompilererrorhandler            setcompilererrorhandler;

        //stack operations
        SqLibAPI_push                               push;
        SqLibAPI_pop                                pop;
        SqLibAPI_poptop                             poptop;
        SqLibAPI_remove                             remove;
        SqLibAPI_gettop                             gettop;
        SqLibAPI_settop                             settop;
        SqLibAPI_reservestack                       reservestack;
        SqLibAPI_cmp                                cmp;
        SqLibAPI_move                               move;

        //object creation handling
        SqLibAPI_newuserdata                        newuserdata;
        SqLibAPI_newtable                           newtable;
        SqLibAPI_newtableex                         newtableex;
        SqLibAPI_newarray                           newarray;
        SqLibAPI_newclosure                         newclosure;
        SqLibAPI_setparamscheck                     setparamscheck;
        SqLibAPI_bindenv                            bindenv;
        SqLibAPI_setclosureroot                     setclosureroot;
        SqLibAPI_getclosureroot                     getclosureroot;
        SqLibAPI_pushstring                         pushstring;
        SqLibAPI_pushstringf                        pushstringf;
        SqLibAPI_vpushstringf                       vpushstringf;
        SqLibAPI_pushfloat                          pushfloat;
        SqLibAPI_pushinteger                        pushinteger;
        SqLibAPI_pushbool                           pushbool;
        SqLibAPI_pushuserpointer                    pushuserpointer;
        SqLibAPI_pushnull                           pushnull;
        SqLibAPI_pushthread                         pushthread;
        SqLibAPI_gettype                            gettype;
        SqLibAPI_typeof                             typeof_;
        SqLibAPI_getsize                            getsize;
        SqLibAPI_gethash                            gethash;
        SqLibAPI_getbase                            getbase;
        SqLibAPI_instanceof                         instanceof;
        SqLibAPI_tostring                           tostring;
        SqLibAPI_tobool                             tobool;
        SqLibAPI_getstringandsize                   getstringandsize;
        SqLibAPI_getstring                          getstring;
        SqLibAPI_getinteger                         getinteger;
        SqLibAPI_getfloat                           getfloat;
        SqLibAPI_getbool                            getbool;
        SqLibAPI_getthread                          getthread;
        SqLibAPI_getuserpointer                     getuserpointer;
        SqLibAPI_getuserdata                        getuserdata;
        SqLibAPI_settypetag                         settypetag;
        SqLibAPI_gettypetag                         gettypetag;
        SqLibAPI_setreleasehook                     setreleasehook;
        SqLibAPI_getreleasehook                     getreleasehook;
        SqLibAPI_getscratchpad                      getscratchpad;
        SqLibAPI_getfunctioninfo                    getfunctioninfo;
        SqLibAPI_getclosureinfo                     getclosureinfo;
        SqLibAPI_getclosurename                     getclosurename;
        SqLibAPI_setnativeclosurename               setnativeclosurename;
        SqLibAPI_getnativeclosurepointer            getnativeclosurepointer;
        SqLibAPI_setinstanceup                      setinstanceup;
        SqLibAPI_getinstanceup                      getinstanceup;
        SqLibAPI_setclassudsize                     setclassudsize;
        SqLibAPI_newclass                           newclass;
        SqLibAPI_createinstance                     createinstance;
        SqLibAPI_setattributes                      setattributes;
        SqLibAPI_getattributes                      getattributes;
        SqLibAPI_getclass                           getclass;
        SqLibAPI_weakref                            weakref;
        SqLibAPI_getdefaultdelegate                 getdefaultdelegate;
        SqLibAPI_getmemberhandle                    getmemberhandle;
        SqLibAPI_getbyhandle                        getbyhandle;
        SqLibAPI_setbyhandle                        setbyhandle;

        //object manipulation
        SqLibAPI_pushroottable                      pushroottable;
        SqLibAPI_pushregistrytable                  pushregistrytable;
        SqLibAPI_pushconsttable                     pushconsttable;
        SqLibAPI_setroottable                       setroottable;
        SqLibAPI_setconsttable                      setconsttable;
        SqLibAPI_newslot                            newslot;
        SqLibAPI_deleteslot                         deleteslot;
        SqLibAPI_set                                set;
        SqLibAPI_get                                get;
        SqLibAPI_rawget                             rawget;
        SqLibAPI_rawset                             rawset;
        SqLibAPI_rawdeleteslot                      rawdeleteslot;
        SqLibAPI_newmember                          newmember;
        SqLibAPI_rawnewmember                       rawnewmember;
        SqLibAPI_arrayappend                        arrayappend;
        SqLibAPI_arraypop                           arraypop;
        SqLibAPI_arrayresize                        arrayresize;
        SqLibAPI_arrayreverse                       arrayreverse;
        SqLibAPI_arrayremove                        arrayremove;
        SqLibAPI_arrayinsert                        arrayinsert;
        SqLibAPI_setdelegate                        setdelegate;
        SqLibAPI_getdelegate                        getdelegate;
        SqLibAPI_clone                              clone;
        SqLibAPI_setfreevariable                    setfreevariable;
        SqLibAPI_next                               next;
        SqLibAPI_getweakrefval                      getweakrefval;
        SqLibAPI_clear                              clear;

        //calls
        SqLibAPI_call                               call;
        SqLibAPI_resume                             resume;
        SqLibAPI_getlocal                           getlocal;
        SqLibAPI_getcallee                          getcallee;
        SqLibAPI_getfreevariable                    getfreevariable;
        SqLibAPI_getonefreevariable                 getonefreevariable;
        SqLibAPI_throwerror                         throwerror;
        SqLibAPI_throwerrorf                        throwerrorf;
        SqLibAPI_throwobject                        throwobject;
        SqLibAPI_reseterror                         reseterror;
        SqLibAPI_getlasterror                       getlasterror;

        //raw object handling
        SqLibAPI_getstackobj                        getstackobj;
        SqLibAPI_pushobject                         pushobject;
        SqLibAPI_addref                             addref;
        SqLibAPI_release                            release;
        SqLibAPI_getrefcount                        getrefcount;
        SqLibAPI_resetobject                        resetobject;
        SqLibAPI_objtostring                        objtostring;
        SqLibAPI_objtobool                          objtobool;
        SqLibAPI_objtointeger                       objtointeger;
        SqLibAPI_objtofloat                         objtofloat;
        SqLibAPI_objtouserpointer                   objtouserpointer;
        SqLibAPI_getobjtypetag                      getobjtypetag;
        SqLibAPI_getvmrefcount                      getvmrefcount;

        //GC
        SqLibAPI_collectgarbage                     collectgarbage;
        SqLibAPI_resurrectunreachable               resurrectunreachable;

        //serialization
        SqLibAPI_writeclosure                       writeclosure;
        SqLibAPI_readclosure                        readclosure;

        //mem allocation
        SqLibAPI_malloc                             malloc;
        SqLibAPI_realloc                            realloc;
        SqLibAPI_free                               free;

        //debug
        SqLibAPI_stackinfos                         stackinfos;
        SqLibAPI_setdebughook                       setdebughook;
        SqLibAPI_setnativedebughook                 setnativedebughook;

        //compiler helpers
        SqLibAPI_loadfile                           loadfile;
        SqLibAPI_dofile                             dofile;
        SqLibAPI_writeclosuretofile                 writeclosuretofile;

        //blob
        SqLibAPI_createblob                         createblob;
        SqLibAPI_getblob                            getblob;
        SqLibAPI_getblobsize                        getblobsize;

        //string
        SqLibAPI_format                             format;
    } sqlib_api, SQLIBAPI, *HSQLIBAPI;
    /// @endcond

    /* --------------------------------------------------------------------------------------------
     * Store the API entries from the specified API structure so they can be accessed later.
    */
    SQUIRREL_API int sqlib_api_expand(HSQLIBAPI sqlibapi);

    /* --------------------------------------------------------------------------------------------
     * Undo changes done by sq_api_expand.
    */
    SQUIRREL_API void sqlib_api_collapse();

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*_SQ_PLUGIN_H_*/

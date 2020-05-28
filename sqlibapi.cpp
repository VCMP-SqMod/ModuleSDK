// ////////////////////////////////////////////////////////////////////////////////////////////////
#include "sqlibapi.h"

// ------------------------------------------------------------------------------------------------
static SQLIBAPI g_API{};

//vm
HSQUIRRELVM sq_open(SQInteger initialstacksize) {
	return g_API.open(initialstacksize);
}
HSQUIRRELVM sq_newthread(HSQUIRRELVM friendvm, SQInteger initialstacksize) {
	return g_API.newthread(friendvm, initialstacksize);
}
void sq_seterrorhandler(HSQUIRRELVM v) {
	g_API.seterrorhandler(v);
}
void sq_close(HSQUIRRELVM v) {
	g_API.close(v);
}
void sq_setforeignptr(HSQUIRRELVM v,SQUserPointer p) {
	g_API.setforeignptr(v, p);
}
SQUserPointer sq_getforeignptr(HSQUIRRELVM v) {
	return g_API.getforeignptr(v);
}
void sq_setsharedforeignptr(HSQUIRRELVM v,SQUserPointer p) {
	g_API.setsharedforeignptr(v, p);
}
SQUserPointer sq_getsharedforeignptr(HSQUIRRELVM v) {
	return g_API.getsharedforeignptr(v);
}
void sq_setvmreleasehook(HSQUIRRELVM v,SQRELEASEHOOK hook) {
	g_API.setvmreleasehook(v, hook);
}
SQRELEASEHOOK sq_getvmreleasehook(HSQUIRRELVM v) {
	return g_API.getvmreleasehook(v);
}
void sq_setsharedreleasehook(HSQUIRRELVM v,SQRELEASEHOOK hook) {
	g_API.setsharedreleasehook(v, hook);
}
SQRELEASEHOOK sq_getsharedreleasehook(HSQUIRRELVM v) {
	return g_API.getsharedreleasehook(v);
}
void sq_setprintfunc(HSQUIRRELVM v, SQPRINTFUNCTION printfunc,SQPRINTFUNCTION errfunc) {
	g_API.setprintfunc(v, printfunc, errfunc);
}
SQPRINTFUNCTION sq_getprintfunc(HSQUIRRELVM v) {
	return g_API.getprintfunc(v);
}
SQPRINTFUNCTION sq_geterrorfunc(HSQUIRRELVM v) {
	return g_API.geterrorfunc(v);
}
SQRESULT sq_suspendvm(HSQUIRRELVM v) {
	return g_API.suspendvm(v);
}
SQRESULT sq_wakeupvm(HSQUIRRELVM v,SQBool resumedret,SQBool retval,SQBool raiseerror,SQBool throwerror) {
	return g_API.wakeupvm(v, resumedret, retval, raiseerror, throwerror);
}
SQInteger sq_getvmstate(HSQUIRRELVM v) {
	return g_API.getvmstate(v);
}
SQInteger sq_getversion() {
	return g_API.getversion();
}

//compiler
SQRESULT sq_compile(HSQUIRRELVM v,SQLEXREADFUNC read,SQUserPointer p,const SQChar *sourcename,SQBool raiseerror) {
	return g_API.compile(v, read, p, sourcename, raiseerror);
}
SQRESULT sq_compilebuffer(HSQUIRRELVM v,const SQChar *s,SQInteger size,const SQChar *sourcename,SQBool raiseerror) {
	return g_API.compilebuffer(v, s, size, sourcename, raiseerror);
}
void sq_enabledebuginfo(HSQUIRRELVM v, SQBool enable) {
	g_API.enabledebuginfo(v, enable);
}
void sq_notifyallexceptions(HSQUIRRELVM v, SQBool enable) {
	g_API.notifyallexceptions(v, enable);
}
void sq_setcompilererrorhandler(HSQUIRRELVM v,SQCOMPILERERROR f) {
	g_API.setcompilererrorhandler(v, f);
}

//stack operations
void sq_push(HSQUIRRELVM v,SQInteger idx) {
	g_API.push(v, idx);
}
void sq_pop(HSQUIRRELVM v,SQInteger nelemstopop) {
	g_API.pop(v, nelemstopop);
}
void sq_poptop(HSQUIRRELVM v) {
	g_API.poptop(v);
}
void sq_remove(HSQUIRRELVM v,SQInteger idx) {
	g_API.remove(v, idx);
}
SQInteger sq_gettop(HSQUIRRELVM v) {
	return g_API.gettop(v);
}
void sq_settop(HSQUIRRELVM v,SQInteger newtop) {
	g_API.settop(v, newtop);
}
SQRESULT sq_reservestack(HSQUIRRELVM v,SQInteger nsize) {
	return g_API.reservestack(v, nsize);
}
SQInteger sq_cmp(HSQUIRRELVM v) {
	return g_API.cmp(v);
}
void sq_move(HSQUIRRELVM dest,HSQUIRRELVM src,SQInteger idx) {
	g_API.move(dest, src, idx);
}

//object creation handling
SQUserPointer sq_newuserdata(HSQUIRRELVM v,SQUnsignedInteger size) {
	return g_API.newuserdata(v, size);
}
void sq_newtable(HSQUIRRELVM v) {
	g_API.newtable(v);
}
void sq_newtableex(HSQUIRRELVM v,SQInteger initialcapacity) {
	g_API.newtableex(v, initialcapacity);
}
void sq_newarray(HSQUIRRELVM v,SQInteger size) {
	g_API.newarray(v, size);
}
void sq_newclosure(HSQUIRRELVM v,SQFUNCTION func,SQUnsignedInteger nfreevars) {
	g_API.newclosure(v, func, nfreevars);
}
SQRESULT sq_setparamscheck(HSQUIRRELVM v,SQInteger nparamscheck,const SQChar *typemask) {
	return g_API.setparamscheck(v, nparamscheck, typemask);
}
SQRESULT sq_bindenv(HSQUIRRELVM v,SQInteger idx) {
	return g_API.bindenv(v, idx);
}
SQRESULT sq_setclosureroot(HSQUIRRELVM v,SQInteger idx) {
	return g_API.setclosureroot(v, idx);
}
SQRESULT sq_getclosureroot(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getclosureroot(v, idx);
}
void sq_pushstring(HSQUIRRELVM v,const SQChar *s,SQInteger len) {
	g_API.pushstring(v, s, len);
}
SQRESULT sq_pushstringf(HSQUIRRELVM v,const SQChar *s,...) {
	va_list args;
    va_start(args,s);
	return g_API.vpushstringf(v, s, args);
    va_end(args);
}
SQRESULT sq_vpushstringf(HSQUIRRELVM v,const SQChar *s,va_list l) {
	return g_API.vpushstringf(v, s, l);
}
void sq_pushfloat(HSQUIRRELVM v,SQFloat f) {
	g_API.pushfloat(v, f);
}
void sq_pushinteger(HSQUIRRELVM v,SQInteger n) {
	g_API.pushinteger(v, n);
}
void sq_pushbool(HSQUIRRELVM v,SQBool b) {
	g_API.pushbool(v, b);
}
void sq_pushuserpointer(HSQUIRRELVM v,SQUserPointer p) {
	g_API.pushuserpointer(v, p);
}
void sq_pushnull(HSQUIRRELVM v) {
	g_API.pushnull(v);
}
void sq_pushthread(HSQUIRRELVM v, HSQUIRRELVM thread) {
	g_API.pushthread(v, thread);
}
SQObjectType sq_gettype(HSQUIRRELVM v,SQInteger idx) {
	return g_API.gettype(v, idx);
}
SQRESULT sq_typeof(HSQUIRRELVM v,SQInteger idx) {
	return g_API.typeof(v, idx);
}
SQInteger sq_getsize(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getsize(v, idx);
}
SQHash sq_gethash(HSQUIRRELVM v, SQInteger idx) {
	return g_API.gethash(v, idx);
}
SQRESULT sq_getbase(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getbase(v, idx);
}
SQBool sq_instanceof(HSQUIRRELVM v) {
	return g_API.instanceof(v);
}
SQRESULT sq_tostring(HSQUIRRELVM v,SQInteger idx) {
	return g_API.tostring(v, idx);
}
void sq_tobool(HSQUIRRELVM v, SQInteger idx, SQBool *b) {
	g_API.tobool(v, idx, b);
}
SQRESULT sq_getstringandsize(HSQUIRRELVM v,SQInteger idx,const SQChar **c,SQInteger *size) {
	return g_API.getstringandsize(v, idx, c, size);
}
SQRESULT sq_getstring(HSQUIRRELVM v,SQInteger idx,const SQChar **c) {
	return g_API.getstring(v, idx, c);
}
SQRESULT sq_getinteger(HSQUIRRELVM v,SQInteger idx,SQInteger *i) {
	return g_API.getinteger(v, idx, i);
}
SQRESULT sq_getfloat(HSQUIRRELVM v,SQInteger idx,SQFloat *f) {
	return g_API.getfloat(v, idx, f);
}
SQRESULT sq_getbool(HSQUIRRELVM v,SQInteger idx,SQBool *b) {
	return g_API.getbool(v, idx, b);
}
SQRESULT sq_getthread(HSQUIRRELVM v,SQInteger idx,HSQUIRRELVM *thread) {
	return g_API.getthread(v, idx, thread);
}
SQRESULT sq_getuserpointer(HSQUIRRELVM v,SQInteger idx,SQUserPointer *p) {
	return g_API.getuserpointer(v, idx, p);
}
SQRESULT sq_getuserdata(HSQUIRRELVM v,SQInteger idx,SQUserPointer *p,SQUserPointer *typetag) {
	return g_API.getuserdata(v, idx, p, typetag);
}
SQRESULT sq_settypetag(HSQUIRRELVM v,SQInteger idx,SQUserPointer typetag) {
	return g_API.settypetag(v, idx, typetag);
}
SQRESULT sq_gettypetag(HSQUIRRELVM v,SQInteger idx,SQUserPointer *typetag) {
	return g_API.gettypetag(v, idx, typetag);
}
void sq_setreleasehook(HSQUIRRELVM v,SQInteger idx,SQRELEASEHOOK hook) {
	g_API.setreleasehook(v, idx, hook);
}
SQRELEASEHOOK sq_getreleasehook(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getreleasehook(v, idx);
}
SQChar* sq_getscratchpad(HSQUIRRELVM v,SQInteger minsize) {
	return g_API.getscratchpad(v, minsize);
}
SQRESULT sq_getfunctioninfo(HSQUIRRELVM v,SQInteger level,SQFunctionInfo *fi) {
	return g_API.getfunctioninfo(v, level, fi);
}
SQRESULT sq_getclosureinfo(HSQUIRRELVM v,SQInteger idx,SQInteger *nparams,SQInteger *nfreevars) {
	return g_API.getclosureinfo(v, idx, nparams, nfreevars);
}
SQRESULT sq_getclosurename(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getclosurename(v, idx);
}
SQRESULT sq_setnativeclosurename(HSQUIRRELVM v,SQInteger idx,const SQChar *name) {
	return g_API.setnativeclosurename(v, idx, name);
}
SQRESULT sq_getnativeclosurepointer(HSQUIRRELVM v,SQInteger idx,SQFUNCTION *f) {
	return g_API.getnativeclosurepointer(v, idx, f);
}
SQRESULT sq_setinstanceup(HSQUIRRELVM v, SQInteger idx, SQUserPointer p) {
	return g_API.setinstanceup(v, idx, p);
}
SQRESULT sq_getinstanceup(HSQUIRRELVM v, SQInteger idx, SQUserPointer *p,SQUserPointer typetag) {
	return g_API.getinstanceup(v, idx, p, typetag);
}
SQRESULT sq_setclassudsize(HSQUIRRELVM v, SQInteger idx, SQInteger udsize) {
	return g_API.setclassudsize(v, idx, udsize);
}
SQRESULT sq_newclass(HSQUIRRELVM v,SQBool hasbase) {
	return g_API.newclass(v, hasbase);
}
SQRESULT sq_createinstance(HSQUIRRELVM v,SQInteger idx) {
	return g_API.createinstance(v, idx);
}
SQRESULT sq_setattributes(HSQUIRRELVM v,SQInteger idx) {
	return g_API.setattributes(v, idx);
}
SQRESULT sq_getattributes(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getattributes(v, idx);
}
SQRESULT sq_getclass(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getclass(v, idx);
}
void sq_weakref(HSQUIRRELVM v,SQInteger idx) {
	g_API.weakref(v, idx);
}
SQRESULT sq_getdefaultdelegate(HSQUIRRELVM v,SQObjectType t) {
	return g_API.getdefaultdelegate(v, t);
}
SQRESULT sq_getmemberhandle(HSQUIRRELVM v,SQInteger idx,HSQMEMBERHANDLE *handle) {
	return g_API.getmemberhandle(v, idx, handle);
}
SQRESULT sq_getbyhandle(HSQUIRRELVM v,SQInteger idx,const HSQMEMBERHANDLE *handle) {
	return g_API.getbyhandle(v, idx, handle);
}
SQRESULT sq_setbyhandle(HSQUIRRELVM v,SQInteger idx,const HSQMEMBERHANDLE *handle) {
	return g_API.setbyhandle(v, idx, handle);
}

//object manipulation
void sq_pushroottable(HSQUIRRELVM v) {
	g_API.pushroottable(v);
}
void sq_pushregistrytable(HSQUIRRELVM v) {
	g_API.pushregistrytable(v);
}
void sq_pushconsttable(HSQUIRRELVM v) {
	g_API.pushconsttable(v);
}
SQRESULT sq_setroottable(HSQUIRRELVM v) {
	return g_API.setroottable(v);
}
SQRESULT sq_setconsttable(HSQUIRRELVM v) {
	return g_API.setconsttable(v);
}
SQRESULT sq_newslot(HSQUIRRELVM v, SQInteger idx, SQBool bstatic) {
	return g_API.newslot(v, idx, bstatic);
}
SQRESULT sq_deleteslot(HSQUIRRELVM v,SQInteger idx,SQBool pushval) {
	return g_API.deleteslot(v, idx, pushval);
}
SQRESULT sq_set(HSQUIRRELVM v,SQInteger idx) {
	return g_API.set(v, idx);
}
SQRESULT sq_get(HSQUIRRELVM v,SQInteger idx) {
	return g_API.get(v, idx);
}
SQRESULT sq_rawget(HSQUIRRELVM v,SQInteger idx) {
	return g_API.rawget(v, idx);
}
SQRESULT sq_rawset(HSQUIRRELVM v,SQInteger idx) {
	return g_API.rawset(v, idx);
}
SQRESULT sq_rawdeleteslot(HSQUIRRELVM v,SQInteger idx,SQBool pushval) {
	return g_API.rawdeleteslot(v, idx, pushval);
}
SQRESULT sq_newmember(HSQUIRRELVM v,SQInteger idx,SQBool bstatic) {
	return g_API.newmember(v, idx, bstatic);
}
SQRESULT sq_rawnewmember(HSQUIRRELVM v,SQInteger idx,SQBool bstatic) {
	return g_API.rawnewmember(v, idx, bstatic);
}
SQRESULT sq_arrayappend(HSQUIRRELVM v,SQInteger idx) {
	return g_API.arrayappend(v, idx);
}
SQRESULT sq_arraypop(HSQUIRRELVM v,SQInteger idx,SQBool pushval) {
	return g_API.arraypop(v, idx, pushval);
}
SQRESULT sq_arrayresize(HSQUIRRELVM v,SQInteger idx,SQInteger newsize) {
	return g_API.arrayresize(v, idx, newsize);
}
SQRESULT sq_arrayreverse(HSQUIRRELVM v,SQInteger idx) {
	return g_API.arrayreverse(v, idx);
}
SQRESULT sq_arrayremove(HSQUIRRELVM v,SQInteger idx,SQInteger itemidx) {
	return g_API.arrayremove(v, idx, itemidx);
}
SQRESULT sq_arrayinsert(HSQUIRRELVM v,SQInteger idx,SQInteger destpos) {
	return g_API.arrayinsert(v, idx, destpos);
}
SQRESULT sq_setdelegate(HSQUIRRELVM v,SQInteger idx) {
	return g_API.setdelegate(v, idx);
}
SQRESULT sq_getdelegate(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getdelegate(v, idx);
}
SQRESULT sq_clone(HSQUIRRELVM v,SQInteger idx) {
	return g_API.clone(v, idx);
}
SQRESULT sq_setfreevariable(HSQUIRRELVM v,SQInteger idx,SQUnsignedInteger nval) {
	return g_API.setfreevariable(v, idx, nval);
}
SQRESULT sq_next(HSQUIRRELVM v,SQInteger idx) {
	return g_API.next(v, idx);
}
SQRESULT sq_getweakrefval(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getweakrefval(v, idx);
}
SQRESULT sq_clear(HSQUIRRELVM v,SQInteger idx) {
	return g_API.clear(v, idx);
}

//calls
SQRESULT sq_call(HSQUIRRELVM v,SQInteger params,SQBool retval,SQBool raiseerror) {
	return g_API.call(v, params, retval, raiseerror);
}
SQRESULT sq_resume(HSQUIRRELVM v,SQBool retval,SQBool raiseerror) {
	return g_API.resume(v, retval, raiseerror);
}
const SQChar* sq_getlocal(HSQUIRRELVM v,SQUnsignedInteger level,SQUnsignedInteger idx) {
	return g_API.getlocal(v, level, idx);
}
SQRESULT sq_getcallee(HSQUIRRELVM v) {
	return g_API.getcallee(v);
}
const SQChar* sq_getfreevariable(HSQUIRRELVM v,SQInteger idx,SQUnsignedInteger nval) {
	return g_API.getfreevariable(v, idx, nval);
}
const SQChar* sq_getonefreevariable(HSQUIRRELVM v,SQUnsignedInteger nval) {
	return g_API.getonefreevariable(v, nval);
}
SQRESULT sq_throwerror(HSQUIRRELVM v,const SQChar *err) {
	return g_API.throwerror(v, err);
}
SQRESULT sq_throwerrorf(HSQUIRRELVM v,const SQChar *err,...) {
	return g_API.throwerrorf(v, err);
}
SQRESULT sq_throwobject(HSQUIRRELVM v) {
	return g_API.throwobject(v);
}
void sq_reseterror(HSQUIRRELVM v) {
	g_API.reseterror(v);
}
void sq_getlasterror(HSQUIRRELVM v) {
	g_API.getlasterror(v);
}

//raw object handling
SQRESULT sq_getstackobj(HSQUIRRELVM v,SQInteger idx,HSQOBJECT *po) {
	return g_API.getstackobj(v, idx, po);
}
void sq_pushobject(HSQUIRRELVM v,HSQOBJECT obj) {
	g_API.pushobject(v, obj);
}
void sq_addref(HSQUIRRELVM v,HSQOBJECT *po) {
	g_API.addref(v, po);
}
SQBool sq_release(HSQUIRRELVM v,HSQOBJECT *po) {
	return g_API.release(v, po);
}
SQUnsignedInteger sq_getrefcount(HSQUIRRELVM v,HSQOBJECT *po) {
	return g_API.getrefcount(v, po);
}
void sq_resetobject(HSQOBJECT *po) {
	g_API.resetobject(po);
}
const SQChar* sq_objtostring(const HSQOBJECT *o) {
	return g_API.objtostring(po);
}
SQBool sq_objtobool(const HSQOBJECT *o) {
	return g_API.objtobool(o);
}
SQInteger sq_objtointeger(const HSQOBJECT *o) {
	return g_API.objtointeger(o);
}
SQFloat sq_objtofloat(const HSQOBJECT *o) {
	return g_API.objtofloat(o);
}
SQUserPointer sq_objtouserpointer(const HSQOBJECT *o) {
	return g_API.objtouserpointer(o);
}
SQRESULT sq_getobjtypetag(const HSQOBJECT *o,SQUserPointer * typetag) {
	return g_API.getobjtypetag(o, typetag);
}
SQUnsignedInteger sq_getvmrefcount(HSQUIRRELVM v, const HSQOBJECT *po) {
	return g_API.getvmrefcount(v, po);
}

//GC
SQInteger sq_collectgarbage(HSQUIRRELVM v) {
	return g_API.collectgarbage(v);
}
SQRESULT sq_resurrectunreachable(HSQUIRRELVM v) {
	return g_API.resurrectunreachable(v);
}

//serialization
SQRESULT sq_writeclosure(HSQUIRRELVM vm,SQWRITEFUNC writef,SQUserPointer up) {
	return g_API.writeclosure(vm, writef, up);
}
SQRESULT sq_readclosure(HSQUIRRELVM vm,SQREADFUNC readf,SQUserPointer up) {
	return g_API.readclosure(vm, readf, up);
}

//mem allocation
void* sq_malloc(SQUnsignedInteger size) {
	return g_API.malloc(size);
}
void* sq_realloc(void* p,SQUnsignedInteger oldsize,SQUnsignedInteger newsize) {
	return g_API.realloc(p, oldsize, newsize);
}
void sq_free(void *p,SQUnsignedInteger size) {
	g_API.free(size);
}

//debug
SQRESULT sq_stackinfos(HSQUIRRELVM v,SQInteger level,SQStackInfos *si) {
	return g_API.stackinfos(v, level, si);
}
void sq_setdebughook(HSQUIRRELVM v) {
	g_API.setdebughook(v);
}
void sq_setnativedebughook(HSQUIRRELVM v,SQDEBUGHOOK hook) {
	g_API.setnativedebughook(v, hook);
}

//compiler helpers
SQRESULT sq_loadfile(HSQUIRRELVM v,const SQChar *filename,SQBool printerror) {
	return g_API.loadfile(v, filename, printerror);
}
SQRESULT sq_dofile(HSQUIRRELVM v,const SQChar *filename,SQBool retval,SQBool printerror) {
	return g_API.dofile(v, filename, retval, printerror);
}
SQRESULT sq_writeclosuretofile(HSQUIRRELVM v,const SQChar *filename) {
	return g_API.writeclosuretofile(v, filename);
}

//blob
SQUserPointer sq_createblob(HSQUIRRELVM v, SQInteger size) {
	return g_API.createblob(v, size);
}
SQRESULT sq_getblob(HSQUIRRELVM v,SQInteger idx,SQUserPointer *ptr) {
	return g_API.getblob(v, idx, ptr);
}
SQInteger sq_getblobsize(HSQUIRRELVM v,SQInteger idx) {
	return g_API.getblobsize(v, idx);
}

//string
SQRESULT sq_format(HSQUIRRELVM v,SQInteger nformatstringidx,SQInteger *outlen,SQChar **output) {
	return g_API.format(v, nformatstringidx, outlen, output);
}

// ------------------------------------------------------------------------------------------------
int sqlib_api_expand(HSQLIBAPI sqlibapi)
{
    if (!sqlibapi)
    {
        return 0;
    }

    // Copy API entries
    memcpy(&g_API, sqlibapi, sizeof(SQLIBAPI));

    return 1;
}

// ------------------------------------------------------------------------------------------------
void sqlib_api_collapse()
{
	memset(&g_API, 0, sizeof(SQLIBAPI));
}

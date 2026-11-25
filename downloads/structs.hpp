//=================
// Credoxy 3.1.6
// version-2c6fd5e09aaf4cfa
// dumped 13/13
// dump time: 50.771s
//=================

#define CLOSURE_CONT_ENC vmval3
#define LSTATE_STACKSIZE_ENC vmval1
#define PROTO_ABSLINEINFO_ENC vmval1
#define PROTO_DEBUGINSN_ENC vmval2
#define PROTO_DEBUGNAME_ENC vmval4
#define PROTO_LINEINFO_ENC vmval4
#define PROTO_LOCVARS_ENC vmval2
#define PROTO_SOURCE_ENC vmval4
#define PROTO_TYPEINFO_ENC vmval1
#define PROTO_UPVALUES_ENC vmval1
#define PROTO_USERDATA_ENC vmval4
#define TSTRING_HASH_ENC vmval4
#define UDATA_META_ENC vmval4

struct Proto; struct lua_State; struct global_State;
struct CallInfo; struct LuaTable; struct LuaNode;
struct TString; struct LocVar; struct TValue;
struct Instruction; struct GCObject; struct UpVal;
struct Udata; struct Closure; struct RobloxExtraSpace;
struct Shared; struct SharedExtraSpace; struct Identity;
struct FeedbackVectorSlot; struct GCStats; struct GCMetrics;
struct lua_Callbacks; struct lua_Debug; struct lua_Page;
struct stringtable; struct lua_ExecutionCallbacks;
struct lua_UdataDirectAccessData;
using registryfree_t = int32_t;
using lua_UserdataMark = void(*)(lua_State*, void*);
using lua_EmbedderMark = void(*)(lua_State*, int);
using lua_EmbedderGc = int(*)(lua_State*, lua_EmbedderMark);

typedef TValue* StkId;
typedef void* (*lua_Alloc)(void* ud, void* ptr, size_t osize, size_t nsize);
typedef int (*lua_CFunction)(lua_State* L);
typedef int (*lua_Continuation)(lua_State* L, int status);

#define CommonHeader \
    uint8_t marked; \
    uint8_t tt; \
    uint8_t memcat

#define LUA_EXECUTION_CALLBACK_STORAGE 512
#define LUA_LUTAG_LIMIT            128
#define LUA_MEMORY_CATEGORIES      256
#define LUA_SIZECLASSES            40
#define LUA_T_COUNT                13
#define LUA_UTAG_LIMIT             128
#define TAGGED_PAGESET_SIZE        8
#define TM_N                       21
#define UTAG_INTERNAL_LIMIT        130

struct GCObject {
    CommonHeader;
};

struct Proto {
    CommonHeader;
    uint8_t maxstacksize;
    uint8_t numparams;
    uint8_t is_vararg;
    uint8_t flags;
    uint8_t nups;
    PROTO_ABSLINEINFO_ENC<int*> abslineinfo;
    struct Proto** p;
    PROTO_DEBUGNAME_ENC<TString*> debugname;
    const Instruction* codeentry;
    PROTO_USERDATA_ENC<uint64_t*> userdata;
    PROTO_DEBUGINSN_ENC<uint8_t*> debuginsn;
    uint8_t execflags;
    PROTO_SOURCE_ENC<TString*> source;
    PROTO_LOCVARS_ENC<struct LocVar*> locvars;
    PROTO_UPVALUES_ENC<TString**> upvalues;
    uint32_t execcount;
    void* execdata;
    uintptr_t exectarget;
    TValue* k;
    Instruction* code;
    GCObject* gclist;
    PROTO_LINEINFO_ENC<uint8_t*> lineinfo;
    PROTO_TYPEINFO_ENC<uint8_t*> typeinfo;
    int sizetypeinfo;
    int linegaplog2;
    int sizelineinfo;
    int sizelocvars;
    int linedefined;
    int sizecode;
    int bytecodeid;
    int sizep;
    int sizek;
    int sizeupvalues;
    FeedbackVectorSlot* feedbackvec;
    uint32_t feedbackvecsize;
    uint32_t funid;
    Proto* optimized;
    Proto* deoptimized;
    uint64_t cost;
    struct LuauLazyChunk* lazychunk;
};
static_assert(sizeof(Proto) == 240, "sizeof(Proto) == 240");

struct TString {
    CommonHeader;
    uint16_t atomflag;
    int16_t atom;
    TString* next;
    TSTRING_HASH_ENC<unsigned int> hash;
    unsigned int len;
    char data[1];
};
static_assert(sizeof(TString) == 32, "sizeof(TString) == 32");

struct Udata {
    CommonHeader;
    uint8_t tag;
    int len;
    UDATA_META_ENC<struct LuaTable*> metatable;
    alignas(8) char data[1];
};
static_assert(sizeof(Udata) == 24, "sizeof(Udata) == 24");

struct stringtable {
    uint32_t saltmult;
    uint32_t saltadd;
    uint8_t hashshift;
    TString** hash;
    uint32_t nuse;
    int size;
};
static_assert(sizeof(stringtable) == 32, "sizeof(stringtable) == 32");

struct TValue {
    Value value;
    int extra;
    int tt;
};
static_assert(sizeof(TValue) == 16, "sizeof(TValue) == 16");

struct Closure {
    CommonHeader;
    uint8_t stacksize;
    uint8_t nupvalues;
    uint8_t preload;
    uint8_t isC;
    GCObject* gclist;
    struct LuaTable* env;
    union {
        struct {
            TString* debugname;
            CLOSURE_CONT_ENC<lua_Continuation> cont;
            lua_CFunction f;
            TValue upvals[1];
        } c;
        struct {
            struct Proto* p;
        } l;
    };
};

struct LuaTable {
    CommonHeader;
    uint8_t tmcache;
    uint8_t lsizenode;
    uint8_t readonly;
    uint8_t safeenv;
    uint8_t nodemask8;
    int sizearray;
    int lastfree;
    struct LuaTable* metatable;
    GCObject* gclist;
    TValue* array;
    LuaNode* node;
};
static_assert(sizeof(LuaTable) == 48, "sizeof(LuaTable) == 48");

struct LuaNode {
    TValue val;
    TKey key;
};
static_assert(sizeof(LuaNode) == 32, "sizeof(LuaNode) == 32");

struct CallInfo {
    Proto* p;
    StkId func;
    StkId base;
    StkId top;
    const Instruction* savedpc;
    int nresults;
    unsigned int flags;
};
static_assert(sizeof(CallInfo) == 48, "sizeof(CallInfo) == 48");

struct lua_State {
    CommonHeader;
    uint8_t status;
    uint8_t activememcat;
    bool isactive;
    bool singlestep;
    GCObject* gclist;
    LSTATE_STACKSIZE_ENC<int> stacksize;
    int size_ci;
    CallInfo* end_ci;
    CallInfo* base_ci;
    TString* namecall;
    unsigned short nCcalls;
    unsigned short baseCcalls;
    int cachedslot;
    LuaTable* finalizers;
    UpVal* openupval;
    RobloxExtraSpace* userdata;
    LuaTable* gt;
    CallInfo* ci;
    StkId stack_last;
    global_State* global;
    StkId stack;
    StkId base;
    StkId top;
};
static_assert(sizeof(lua_State) == 136, "sizeof(lua_State) == 136");

struct lua_Callbacks {
    void* userdata;
    void(*debugprotectederror)(lua_State*);
    void(*debugbreak)(lua_State*,lua_Debug*);
    void(*postresume)(lua_State*);
    void(*panic)(lua_State*,int);
    void(*userthread)(lua_State*,lua_State*);
    int16_t(*useratom)(lua_State*,const char*,size_t);
    void(*onallocate)(lua_State*,void*,size_t,size_t,uint8_t,int,int);
    void(*debugstep)(lua_State*,lua_Debug*);
    void(*onfree)(lua_State*,void*);
    void(*debuginterrupt)(lua_State*,lua_Debug*);
    void(*interrupt)(lua_State*,int);
    void(*preresume)(lua_State*);
    void(*userfinalizer)(lua_State*,lua_State*);
};
static_assert(sizeof(lua_Callbacks) == 112, "sizeof(lua_Callbacks) == 112");

struct lua_Page {
    lua_Page* listprev;
    lua_Page* listnext;
    lua_Page* prev;
    lua_Page* next;
    int pageSize;
    int blockSize;
    void* freeList;
    int freeNext;
    int busyBlocks;
    int flags;
    char padding[8];
    char data[1];
};

struct lua_Debug {
    uint8_t nparams;
    uint8_t nupvals;
    uint8_t isvararg;
    int linedefined;
    int bytecodeid;
    int protoid;
    int currentline;
    void* userdata;
    const char* short_src;
    const char* what;
    const char* name;
    const char* source;
    char ssbuf;
};

struct lua_ExecutionCallbacks {
    void* context;
    void(*close)(lua_State*);
    void(*destroy)(lua_State*, Proto*);
    int(*enter)(lua_State*, Proto*);
    void(*disable)(lua_State*, Proto*);
    size_t(*getmemorysize)(lua_State*, Proto*);
    uint8_t(*gettypemapping)(lua_State*, const char*, size_t);
    void(*onallocate)(lua_State*, void*, size_t);
    void(*onfree)(lua_State*, void*);
    void(*onresize)(lua_State*, void*, size_t, size_t);
    void* userdata;
};
static_assert(sizeof(lua_ExecutionCallbacks) == 88, "sizeof(lua_ExecutionCallbacks) == 88");

struct UpVal {
    CommonHeader;
    uint8_t markedopen;
    TValue* v;
    TValue value;
    uint64_t open_extra;
};
static_assert(sizeof(UpVal) == 40, "sizeof(UpVal) == 40");

struct GCStats {
    int32_t triggerterms[32];
    uint32_t triggertermpos;
    int32_t triggerintegral;
    size_t timesincelastgc;
    double starttimestamp;
    double endtimestamp;
    size_t starttotalsizebytes;
    size_t endtotalsizebytes;
    size_t heapgoalsizebytes;
};
static_assert(sizeof(GCStats) == 184, "sizeof(GCStats) == 184");

struct GCMetrics {
    double stepexplicittimeacc;
    double stepassisttimeacc;
    uint64_t completedcycles;
    uint64_t details[57];
};
static_assert(sizeof(GCMetrics) == 480, "sizeof(GCMetrics) == 480");

struct lua_UdataDirectAccessData {
    TValue metatable;
    LuaTable* udatamt;
    size_t size;
    void* get;
    void* set;
    void* namecall;
    void* index;
    void* newindex;
};
static_assert(sizeof(lua_UdataDirectAccessData) == 72, "sizeof(lua_UdataDirectAccessData) == 72");

struct LuauPageset {
    lua_Page* freepages[LUA_SIZECLASSES];
    lua_Page* allpages;
    lua_Page* sweepgcopage;
};
static_assert(sizeof(LuauPageset) == 336, "sizeof(LuauPageset) == 336");

struct global_State {
    stringtable strt;
    lua_Alloc frealloc;
    void* ud;
    size_t GCthreshold;
    size_t totalbytes;
    GCObject* gray;
    GCObject* weak;
    GCObject* grayagain;
    uint8_t currentwhite;
    uint8_t gcdisabled;
    uint8_t gcstate;
    int gcgoal;
    int gcstepmul;
    int gcstepsize;
    struct lua_Page* freepages[LUA_SIZECLASSES];
    struct lua_Page* allgcopages;
    struct lua_Page* freegcopages[LUA_SIZECLASSES];
    struct lua_State* mainthread;
    struct lua_Page* allpages;
    struct lua_Page* sweepgcopage;
    UpVal uvhead;
    struct LuaTable* mt[LUA_T_COUNT];
    TString* tmname[TM_N];
    TString* ttname[LUA_T_COUNT];
    void* cagealloc;
    struct lua_Page* allgcopages_cage;
    struct lua_Page* freegcopages_cage[LUA_SIZECLASSES];
    struct lua_Page* sweepgcopage_cage;
    void* cageud;
    TValue pseudotemp;
    TValue registry;
    registryfree_t registryfree;
    lua_Callbacks cb;
    uint64_t ptrenckey[4];
    uint64_t rngstate;
    void* errorjmp;
    lua_ExecutionCallbacks ecb;
    alignas(16) uint8_t ecbdata[LUA_EXECUTION_CALLBACK_STORAGE];
    lua_UdataDirectAccessData udatadirect[UTAG_INTERNAL_LIMIT];
    LuauPageset taggedpageset[TAGGED_PAGESET_SIZE];
    int sweeppageset;
    size_t memcatbytes[LUA_MEMORY_CATEGORIES];
    void(*udatagc[LUA_UTAG_LIMIT])(lua_State*,void*);
    lua_UserdataMark udatamark[LUA_UTAG_LIMIT];
    LuaTable* udatamt[LUA_UTAG_LIMIT];
    TValue weakregistry;
    int weakregistryfree;
    int weakregistrytop;
    lua_EmbedderGc embeddergc;
    TString* lightuserdataname[LUA_LUTAG_LIMIT];
    LuaTable* udatadirectfields[UTAG_INTERNAL_LIMIT];
    struct Closure* builtinPcall;
    struct Closure* builtinXpcall;
    uint64_t ptrenckeynew[8];
    bool ptrencactive;
    GCStats gcstats;
    uint32_t lastprotoid;
    uint32_t lastclassid;
    GCMetrics gcmetrics;
};
static_assert(sizeof(global_State) == 22384, "sizeof(global_State) == 22384");

struct SharedThreads {
    uint64_t count;
    RobloxExtraSpace* head;
};

struct Shared {
    int threadCount;
    void* scriptContext;
    void* scriptVmState;
    void* engineContext;
    SharedThreads allThreads;
};

struct Identity {
    uint32_t type;
    uint64_t assetId;
};
static_assert(sizeof(Identity) == 16, "sizeof(Identity) == 16");

struct RobloxExtraSpace {
    RobloxExtraSpace* next;
    SharedThreads* _container;
    RobloxExtraSpace* prev;
    std::shared_ptr<Shared> shared;
    void* node;
    Identity identity;
    uint64_t identityFlags;
    uint64_t capabilities;
    void* scriptContext;
    uint64_t scriptContextMetadata;
    void* stringId;
    std::weak_ptr<void> script;
    std::weak_ptr<void> actor;
    std::weak_ptr<const void> InstanceDefiningCapabilities;
    void* targetInstance;
    bool isThreadTerminated;
    bool isYielded;
    uint8_t flags[2];
    uint32_t threadFlags;
    void* customThreadData;
    void* context;
};
static_assert(sizeof(RobloxExtraSpace) == 184, "sizeof(RobloxExtraSpace) == 184");

struct SharedExtraSpace {
    int threadCount;
    uintptr_t ScriptContext;
};

struct LocVar {
    TString* varname;
    int startpc;
    int endpc;
    uint8_t reg;
};
static_assert(sizeof(LocVar) == 24, "sizeof(LocVar) == 24");



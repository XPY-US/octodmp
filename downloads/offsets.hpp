//=================
// Credoxy 3.1.6
// version-2c6fd5e09aaf4cfa
// dumped 284/284
// dump time: 72.055s
//=================

#pragma once
#include <cstdint>
#include <windows.h>

#define REBASE(x) ((uintptr_t)GetModuleHandle(0) + (x))

namespace Credoxy
{
    inline const uintptr_t Print = REBASE(0x1BF4F90);
    inline const uintptr_t OpcodeLookupTable = REBASE(0x72C97B0);
    inline const uintptr_t OpcodeDecodeTable = REBASE(0x72C98B0);
    inline const uintptr_t ScriptContextResume = REBASE(0x41D21D0);
    inline const uintptr_t GetLuaStateForInstance = REBASE(0x412F350);
    inline const uintptr_t LuaVMLoad = REBASE(0x4123AB0);
    inline const uintptr_t luaD_throw = REBASE(0x2551BB0);

    namespace Task
    {
        inline const uintptr_t Defer = REBASE(0x4211E10);
        inline const uintptr_t Spawn = REBASE(0x42122E0);
        inline const uintptr_t Delay = REBASE(0x42127E0);
        inline const uintptr_t Wait = REBASE(0x4212AD0);
        inline const uintptr_t Cancel = REBASE(0x4212DA0);
    }

    namespace Reflections
    {
        inline const uintptr_t CastArgs = REBASE(0x408A130);
    }

    namespace Attribute
    {
        inline const uintptr_t NullType = REBASE(0x8D8A590);
        inline const uintptr_t ArrayType = REBASE(0x8D8ADB0);
        inline const uintptr_t DictionaryType = REBASE(0x8D8AE50);
        inline constexpr uintptr_t ListOffset = 0x8;
        inline constexpr uintptr_t CountOffset = 0x10;
        inline constexpr uintptr_t EntryStride = 0x58;
        inline constexpr uintptr_t VariantOffset = 0x8;
        inline constexpr uintptr_t TypeNumOffset = 0x30;
    }

    namespace RemoteFunction
    {
        inline const uintptr_t InvokeServer = REBASE(0x343A3D0);
        inline const uintptr_t SendInvokeClientResult = REBASE(0x343C450);
        inline const uintptr_t EventInvokeClient = REBASE(0x854F7F0);
        inline const uintptr_t ProcessRemoteEvent = REBASE(0x343B470);
    }

    namespace Signals
    {
        inline const uintptr_t FireTouchInterest = REBASE(0x14AE6D0);
        inline const uintptr_t DisconnectConnect = REBASE(0x40F6670);
    }

    namespace signal_offsets
    {
        inline constexpr uintptr_t signature = 0x60;
        namespace connection
        {
            inline constexpr uintptr_t next = 0x10;
            inline constexpr uintptr_t enabled = 0x20;
            inline constexpr uintptr_t slot_wrapper = 0x30;
            inline constexpr uintptr_t slot_wrapper_self = 0x38;
        }

        namespace getter
        {
            inline constexpr uintptr_t chain = 0x68;
            inline constexpr uintptr_t self = 0x18;
            inline constexpr uintptr_t container = 0x50;
            inline constexpr uintptr_t container_thread = 0x28;
        }

        namespace slot_wrapper
        {
            inline constexpr uintptr_t thread = 0x28;
            inline constexpr uintptr_t function_id = 0x30;
            inline constexpr uintptr_t function_id_fallback = 0x34;
            inline constexpr uintptr_t weak_object_ref = 0xA0;
            inline constexpr uintptr_t weak_object_ref_fallback = 0x90;
            inline constexpr uintptr_t weak_object_ref_legacy = 0x68;
        }
    }

    namespace signal_slot
    {
        inline constexpr uintptr_t is_once = 0xB5;
    }

    namespace Flags
    {
        inline const uintptr_t FireLeftMouseClick = REBASE(0x3B3CAC0);
        inline const uintptr_t FireRightMouseClick = REBASE(0x3B3CC60);
        inline const uintptr_t FireMouseHoverEnter = REBASE(0x3B3E030);
        inline const uintptr_t FireMouseHoverLeave = REBASE(0x3B3E1D0);
        inline const uintptr_t FireProximityPrompt = REBASE(0x2FC3D70);
        inline const uintptr_t TaskSchedulerTargetFps = REBASE(0x8104130);
    }

    namespace Luau
    {
        inline constexpr uintptr_t ScriptContextToLuaState = 0x288;
        inline const uintptr_t Luau_Execute = REBASE(0x258E0C0);
        inline const uintptr_t ConstructObject = REBASE(0x25AE5C0);
        inline const uintptr_t DefaultCreateObject = REBASE(0x25AFBB0);
        inline const uintptr_t LuaO_NilObject = REBASE(0x67DBCA8);
        inline const uintptr_t LuaH_DummyNode = REBASE(0x67C4778);
        inline const uintptr_t loadsafe = REBASE(0x25781D0);
        inline const uintptr_t require_bypass_fn = REBASE(0x41E2020);
        inline const uintptr_t lua_resume = REBASE(0x25577C0);
        inline const uintptr_t CoroutineCreate = REBASE(0x58F7DC0);
        inline const uintptr_t CoroutineYield = REBASE(0x58F8650);
        inline const uintptr_t CoroutineStatus = REBASE(0x58F5860);
        inline const uintptr_t CoroutineWrap = REBASE(0x58F8380);
        inline const uintptr_t CoroutineIsYieldable = REBASE(0x58F8730);
        inline const uintptr_t luaV_gettable = REBASE(0x256CF00);
        inline const uintptr_t lua_checkstack = REBASE(0x254B930);
        inline const uintptr_t pseudo2addr = REBASE(0x254B780);
        inline const uintptr_t lua_error = REBASE(0x254FC60);
        inline const uintptr_t lua_newstate = REBASE(0x255A2D0);
        inline const uintptr_t luaL_register = REBASE(0x255FF60);
        inline const uintptr_t luaB_string_byte = REBASE(0x58D6E60);
        inline const uintptr_t luaB_string_char = REBASE(0x58D70F0);
        inline const uintptr_t luaB_string_find = REBASE(0x58D97A0);
        inline const uintptr_t luaB_string_format = REBASE(0x58DBFF0);
        inline const uintptr_t luaB_string_gmatch = REBASE(0x58D9AD0);
        inline const uintptr_t luaB_string_gsub = REBASE(0x58DB620);
        inline const uintptr_t luaB_string_len = REBASE(0x58D4B60);
        inline const uintptr_t luaB_string_lower = REBASE(0x58D6180);
        inline const uintptr_t luaB_string_match = REBASE(0x58D97B0);
        inline const uintptr_t luaB_string_rep = REBASE(0x58D6440);
        inline const uintptr_t luaB_string_reverse = REBASE(0x58D6030);
        inline const uintptr_t luaB_string_sub = REBASE(0x58D4C10);
        inline const uintptr_t luaB_string_upper = REBASE(0x58D62E0);
        inline const uintptr_t luaB_string_split = REBASE(0x58DC580);
        inline const uintptr_t luaB_string_pack = REBASE(0x58E1110);
        inline const uintptr_t luaB_string_packsize = REBASE(0x58E1A80);
        inline const uintptr_t luaB_string_unpack = REBASE(0x58E1DF0);
        inline const uintptr_t luaB_table_concat = REBASE(0x58BDFB0);
        inline const uintptr_t luaB_table_insert = REBASE(0x58BCE90);
        inline const uintptr_t luaB_table_remove = REBASE(0x58BD030);
        inline const uintptr_t luaB_table_sort = REBASE(0x58C0610);
        inline const uintptr_t luaB_table_pack = REBASE(0x58BE2E0);
        inline const uintptr_t luaB_table_unpack = REBASE(0x58BEF50);
        inline const uintptr_t luaB_table_move = REBASE(0x58BD3B0);
        inline const uintptr_t luaB_table_create = REBASE(0x58C07A0);
        inline const uintptr_t luaB_table_clear = REBASE(0x58C1560);
        inline const uintptr_t luaB_table_freeze = REBASE(0x58C15B0);
        inline const uintptr_t luaB_table_isfrozen = REBASE(0x58C1710);
        inline const uintptr_t luaB_table_clone = REBASE(0x58C17C0);
        inline const uintptr_t luaB_table_find = REBASE(0x58C0FA0);
        inline const uintptr_t luaB_table_maxn = REBASE(0x58BB960);
        inline const uintptr_t luaB_table_foreach = REBASE(0x58BA7C0);
        inline const uintptr_t luaB_table_foreachi = REBASE(0x58B9A40);
        inline const uintptr_t luaB_table_getn = REBASE(0x58BBC30);
        inline const uintptr_t lua_pushfstring = REBASE(0x254CDB0);
        inline const uintptr_t luaL_argerror = REBASE(0x255A830);
        inline const uintptr_t luaL_error = REBASE(0x255B8F0);
        inline const uintptr_t luaL_getmetafield = REBASE(0x255E420);
        inline const uintptr_t dumpgco = REBASE(0x258A110);
        inline const uintptr_t luaC_dump = REBASE(0x423BBC0);
        inline const uintptr_t luaC_init = REBASE(0x25A96D0);
        inline const uintptr_t luaC_step = REBASE(0x2575E10);
        inline const uintptr_t luaF_freeproto = REBASE(0x2587E10);
        inline const uintptr_t luaG_runerror = REBASE(0x2586610);
        inline const uintptr_t luaH_clone = REBASE(0x25825E0);
        inline const uintptr_t luaM_visitgco = REBASE(0x25A8B20);
        inline const uintptr_t luaO_pushfstring = REBASE(0x25851A0);
        inline const uintptr_t newpage = REBASE(0x25A8E40);
        inline const uintptr_t tclone = REBASE(0x58C17C0);
        inline const uintptr_t luaB_assert = REBASE(0x58C7E80);
        inline const uintptr_t luaB_error = REBASE(0x58C2F50);
        inline const uintptr_t luaB_gcinfo = REBASE(0x58C5C90);
        inline const uintptr_t luaB_getfenv = REBASE(0x58C4A80);
        inline const uintptr_t luaB_getmetatable = REBASE(0x58C3EA0);
        inline const uintptr_t luaB_next = REBASE(0x58C7380);
        inline const uintptr_t luaB_newproxy = REBASE(0x58C8AD0);
        inline const uintptr_t luaB_print = REBASE(0x58C2AF0);
        inline const uintptr_t luaB_rawequal = REBASE(0x58C4D90);
        inline const uintptr_t luaB_rawget = REBASE(0x58C4EB0);
        inline const uintptr_t luaB_rawset = REBASE(0x58C5440);
        inline const uintptr_t luaB_rawlen = REBASE(0x58C5BF0);
        inline const uintptr_t luaB_select = REBASE(0x58C7F30);
        inline const uintptr_t luaB_setfenv = REBASE(0x58C4B50);
        inline const uintptr_t luaB_setmetatable = REBASE(0x58C4040);
        inline const uintptr_t luaB_tonumber = REBASE(0x58C2BB0);
        inline const uintptr_t luaB_tostring = REBASE(0x58C8A70);
        inline const uintptr_t luaB_type = REBASE(0x58C5CB0);
        inline const uintptr_t luaB_typeof = REBASE(0x58C6820);
        inline const uintptr_t luaopen_coroutine = REBASE(0x58FB100);
        inline const uintptr_t luaopen_table = REBASE(0x58C18D0);
        inline const uintptr_t luaopen_os = REBASE(0x58D4B30);
        inline const uintptr_t luaopen_string = REBASE(0x58E58B0);
        inline const uintptr_t luaopen_math = REBASE(0x58EBC70);
        inline const uintptr_t luaopen_debug = REBASE(0x58F5830);
        inline const uintptr_t luaopen_utf8 = REBASE(0x58D02A0);
        inline const uintptr_t luaopen_bit32 = REBASE(0x58FFCB0);
        inline const uintptr_t luaopen_buffer = REBASE(0x58F1AD0);
        inline const uintptr_t luaopen_vector = REBASE(0x58E7840);
        inline const uintptr_t luaG_concaterror = REBASE(0x25857D0);
        inline const uintptr_t luaG_aritherror = REBASE(0x2585820);
        inline const uintptr_t luaG_ordererror = REBASE(0x25858C0);
        inline const uintptr_t luaG_indexerror = REBASE(0x2585940);
        inline const uintptr_t luaG_methoderror = REBASE(0x2585A40);
        inline const uintptr_t luaG_readonlyerror = REBASE(0x2585A80);
    }

    namespace Extras
    {
        inline const uintptr_t Ktable = REBASE(0x8479B18);
    }

    namespace Raycast
    {
        inline const uintptr_t RaycastBoundDesc = REBASE(0x858FBE0);
        inline constexpr uintptr_t RaycastBoundFn = 0x58;
        inline constexpr uintptr_t RaycastTargetRVA = 0xCDF8B0;
    }

    namespace ExtraSpace
    {
        inline constexpr uintptr_t RequireBypass = 0xBC4;
        inline constexpr uintptr_t IsCoreScript = 0x130;
        inline constexpr uintptr_t CoreState = 0x138;
        inline constexpr uintptr_t ScriptContextToResume = 0x9E8;
    }

    namespace ScriptContext
    {
        inline constexpr uintptr_t CoreState = 0x708;
        inline const uintptr_t GetGlobalState = REBASE(0x412F350);
    }

    namespace InstanceBridge
    {
        inline const uintptr_t Push = REBASE(0x41140D0);
    }

    namespace ClassDescriptor
    {
        inline const uintptr_t HashLookUp = REBASE(0x296B660);
        inline const uintptr_t GetPropertyData = REBASE(0x1C32C90);
        inline const uintptr_t GetProperty = REBASE(0x1C2F7D0);
        inline constexpr uintptr_t Properties = 0x28;
        inline constexpr uintptr_t MemberMapCapacity = 0x1EC;
    }

    namespace Attributes
    {
        inline const uintptr_t GetAttributeContainer = REBASE(0x1C4C950);
        inline const uintptr_t GetAttribute = REBASE(0x1C46AB0);
    }

    namespace RobloxThread
    {
        inline const uintptr_t IdentityPtr = REBASE(0x84AED78);
        inline const uintptr_t GetTlsPointer = REBASE(0xC700);
    }

    namespace Capabilities
    {
        inline const uintptr_t GetCapabilities = REBASE(0x1C31460);
        inline constexpr uintptr_t Capabilities = 0x28;
    }

    namespace Bytecode
    {
        inline constexpr uintptr_t Pointer = 0x18;
        inline constexpr uintptr_t Size = 0x28;
        inline constexpr uintptr_t Capacity = 0x30;
        inline constexpr uintptr_t LocalScriptByteCode = 0x178;
        inline constexpr uintptr_t ModuleScriptByteCode = 0x120;
    }

    namespace DataModel
    {
        inline const uintptr_t FakeDM = REBASE(0x8E16368);
        inline constexpr uintptr_t DataModel = 0x1F8;
        inline constexpr uintptr_t PlaceId = 0x1A0;
        inline constexpr uintptr_t Children = 0x70;
        inline constexpr uintptr_t GameId = 0x198;
        inline constexpr uintptr_t JobId = 0x108;
        inline constexpr uintptr_t ScriptContext = 0x440;
        inline constexpr uintptr_t LocalPlayer = 0x118;
        inline constexpr uintptr_t GameLoaded = 0x5B8;
    }

    namespace Instance
    {
        inline constexpr uintptr_t This = 0x8;
        inline constexpr uintptr_t NameContainer = 0x68;
        inline constexpr uintptr_t Name = 0x0;
        inline constexpr uintptr_t ChildrenStart = 0x70;
        inline constexpr uintptr_t ChildrenEnd = 0x8;
        inline constexpr uintptr_t ChildStride = 0x10;
        inline constexpr uintptr_t ValueBase = 0xA0;
        inline constexpr uintptr_t Parent = 0x60;
        inline constexpr uintptr_t ClassDescriptor = 0x18;
        inline constexpr uintptr_t ClassName = 0x8;
        inline constexpr uintptr_t ClassBase = 0x1B8;
        inline constexpr uintptr_t ComponentMap = 0x38;
    }

    namespace VisualEngine
    {
        inline const uintptr_t Pointer = REBASE(0x8896B98);
        inline constexpr uintptr_t RenderView = 0xC50;
        inline constexpr uintptr_t FakeDataModel = 0xAF0;
        inline constexpr uintptr_t Dimensions = 0xB10;
        inline constexpr uintptr_t ViewMatrix = 0x1B0;
        inline constexpr uintptr_t RenderJobToView = 0x1E0;
        inline constexpr uintptr_t ViewToDevice = 0x10;
        inline constexpr uintptr_t DeviceToSwapChain = 0x80;
    }

    namespace PropertyDescriptor
    {
        inline constexpr uintptr_t ReadCapabilities = 0x38;
        inline constexpr uintptr_t TypeInfo = 0x70;
        inline constexpr uintptr_t GetSet = 0xB0;
        inline constexpr uintptr_t PropertyDescriptorBitFlags = 0xAC;
        inline constexpr uintptr_t ScriptableMask = 0x10;
        inline constexpr uintptr_t Name = 0x8;
    }

    namespace PropertyValue
    {
        inline const uintptr_t OperatorDelete = REBASE(0x4955AC0);
        inline const uintptr_t NetAssetRefDtor = REBASE(0x1C23F40);
        inline const uintptr_t AssetContentMapDtor = REBASE(0xA2BC20);
    }

    namespace Scripts
    {
        inline constexpr uintptr_t weak_thread_live_thread = 0x28;
        inline constexpr uintptr_t weak_thread_live = 0x20;
        inline constexpr uintptr_t weak_thread_node = 0x180;
        inline constexpr uintptr_t weak_thread_ref = 0x8;
    }

    namespace Render
    {
        inline constexpr uintptr_t RenderJobToRenderView = 0x1E0;
        inline constexpr uintptr_t RenderViewToRobloxDevice = 0x10;
        inline constexpr uintptr_t RobloxDeviceToSwapChain = 0x80;
    }

    namespace Properties
    {
        inline constexpr uintptr_t CallbackOffsetInDescriptor = 0x88;
        inline constexpr uintptr_t CallbackOwnerOffset = 0x0;
        inline constexpr uintptr_t CallbackFunctionOffset = 0x10;
        inline constexpr uintptr_t LiveThreadRefOffset = 0x10;
        inline constexpr uintptr_t CallbackThreadOffset = 0x28;
        inline constexpr uintptr_t LuaStateGlobalOffset = 0x68;
        inline constexpr uintptr_t FunctionRefIdOffset = 0x34;
        inline constexpr uintptr_t HolderSelfOffset = 0x38;
        inline constexpr uintptr_t AlternateHolderAdjustment = 0x1F0;
        inline constexpr int CallbackSearchDepth = 5;
        inline constexpr uintptr_t CallbackSearchFields[] = { 0x0, 0x10, 0x28 };
    }

    namespace Scheduler
    {
        inline const uintptr_t TaskScheduler = REBASE(0x8DA5D98);
        inline constexpr uintptr_t JobStart = 0xC8;
        inline constexpr uintptr_t JobEnd = 0xD0;
        inline constexpr uintptr_t JobTypeName = 0x18;
        inline constexpr uintptr_t Fps = 0xB0;
    }

    namespace Raknet
    {
        inline const uintptr_t Receive = REBASE(0x278A600);
        inline const uintptr_t ReportNetworkError = REBASE(0x483B8D0);
        inline const uintptr_t HandleConnectionState = REBASE(0x483E690);
        inline const uintptr_t ReliabilityLayerSend = REBASE(0x278D070);
        inline const uintptr_t Send = REBASE(0x2768720);
        inline const uintptr_t ProcessNetworkPacket = REBASE(0x2774B20);
        inline const uintptr_t UpdateNetworkLoop = REBASE(0x275E520);
        inline const uintptr_t SendPacketsToSelf = REBASE(0x275E110);
        inline const uintptr_t RakPeerReceive = REBASE(0x275FC20);
        inline const uintptr_t RakPeerVTable = REBASE(0x704EE60);
        inline const uintptr_t ConvertItemEnumToString = REBASE(0x47A4370);
        inline const uintptr_t Encrypt = REBASE(0x2790A0C);
    }

    namespace RbxTransport
    {
        inline const uintptr_t ClientVTable = REBASE(0x70B4F38);
        inline const uintptr_t AppVTable = REBASE(0x70420D0);
        inline const uintptr_t ClientDestructor = REBASE(0x39CE300);
        inline const uintptr_t AppDestructor = REBASE(0x2077560);
        inline const uintptr_t ClientSend = REBASE(0x39CE420);
        inline const uintptr_t ClientReceive = REBASE(0x39CEB80);
        inline const uintptr_t ClientChannelConfig = REBASE(0x39CE100);
        inline const uintptr_t AppSend = REBASE(0x2071AE0);
        inline const uintptr_t AppReceive = REBASE(0x2071EB0);
        inline const uintptr_t AppReceiveMaxBytes = REBASE(0x20727F0);
        inline const uintptr_t StreamCreate = REBASE(0x526AC40);
        inline const uintptr_t StreamAppend = REBASE(0x207B190);
        inline const uintptr_t StreamDestroy = REBASE(0x203A6B0);
        inline const uintptr_t ClientRtti = REBASE(0x77F7380);
        inline const uintptr_t AppRtti = REBASE(0x777FA58);
        inline const uintptr_t UseRbxTransportClient = REBASE(0x811C498);
        inline const uintptr_t FailureFallbackToRbxTransport = REBASE(0x8135AB8);
        inline const uintptr_t Encrypt = REBASE(0x2155A40);
        inline const uintptr_t Decrypt = REBASE(0x2155BF0);
    }

    namespace FFlags
    {
        inline const uintptr_t GetFFlag = REBASE(0x498A7C0);
        inline const uintptr_t SetFFlag = REBASE(0x4989CC0);
        inline const uintptr_t FFlagPointer = REBASE(0x84E2BF8);
        inline const uintptr_t BooleanType = REBASE(0x7147908);
        inline const uintptr_t BooleanValueType = REBASE(0x71477F0);
        inline const uintptr_t IntegerType = REBASE(0x7147A20);
        inline const uintptr_t IntegerValueType = REBASE(0x7147B38);
        inline const uintptr_t ClientApplyDmTrackingCapabilities = REBASE(0x80E5CA8);
        inline const uintptr_t LuauLoadExplicitGcDisable = REBASE(0x8167460);
        inline const uintptr_t LuauSaltedInterningTable = REBASE(0x8167440);
        inline const uintptr_t LuauCageSplitData = REBASE(0x81679A8);
        inline const uintptr_t LuauBufferCage = REBASE(0x81673C0);
        inline const uintptr_t LuauBufferSweep = REBASE(0x81679C8);
        inline const uintptr_t DLICAdmitSeedlessDetects = REBASE(0x8144438);
    }
}

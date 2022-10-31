#include <XPLMDefs.h>
#include <XPLMPlugin.h>
#include <XPLMProcessing.h>
#include <XPLMGraphics.h>
#include <XPLMUtilities.h>

#include <string.h>
#include <sstream>

float flighloopCb(float /*inElapsedSinceLastCall*/, float /*inElapsedTimeSinceLastFlightLoop*/, int /*inCounter*/, void * /*inRefcon*/)
{
    static const char *text = "Move Checklist Window Down";
    auto sz = strlen(text);

    auto m = XPLMMeasureString(xplmFont_Proportional, text, sz);

    std::stringstream s;
    s << "text len = " << m << "\n";

    XPLMDebugString(s.str().c_str());
    return 1.0f;
}

PLUGIN_API int XPluginStart(char *outName, char *outSig, char *outDesc)
{
    strcpy(outName, "A plugin");
    strcpy(outSig, "com.plugin.a");
    strcpy(outDesc, "A X-Plane plugin");
    return 1;
}

PLUGIN_API void XPluginStop(void) {}

PLUGIN_API void XPluginDisable(void)
{
    XPLMUnregisterFlightLoopCallback(flighloopCb, NULL);
}

PLUGIN_API int XPluginEnable(void)
{
    XPLMRegisterFlightLoopCallback(flighloopCb, 1, nullptr);
    return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID /*inFrom*/, int /*inMsg*/, void * /*inParam*/)
{
}

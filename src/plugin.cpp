#include <XPLMDefs.h>
#include <XPLMPlugin.h>
#include <XPLMProcessing.h>
#include <XPLMUtilities.h>

#include <string.h>

float flighloopCb(float /*inElapsedSinceLastCall*/, float /*inElapsedTimeSinceLastFlightLoop*/, int /*inCounter*/, void * /*inRefcon*/)
{
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

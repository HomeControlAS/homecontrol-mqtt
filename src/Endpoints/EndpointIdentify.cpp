#include "EndpointIdentify.h"
#include "../HomeControlMagic.h"
#include "../helperFunctions.h"

//#define ENDPOINT_IDENTIFY_DEBUG

static char* const CONFIG = "id";

EndpointIdentify::EndpointIdentify(HomeControlMagic* hcm_ptr, int8_t pin)
    : Endpoint(hcm_ptr)
    , m_pin(pin)
{
  m_config = CONFIG;
}

void EndpointIdentify::incomingMessage(char* topic, uint8_t* payload, unsigned int length)
{
#ifdef ENDPOINT_IDENTIFY_DEBUG
    Serial.println(F("incoming message, EndpointIdentify"));

    for(int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();
#endif

  if(lineContains(topic, "ci"))
  {
    bool state = extractBool(payload, length);
  }
}
#pragma once

#include "Endpoint.h"
#include "helperFunctions.h"

class EndpointColor : public Endpoint
{
public:
    EndpointColor(HomeControlMagic* hcm_ptr, double start_level = 0, int r = 0, int g = 0, int b = 0);

    virtual void sendFeedbackMessage();

    virtual void incomingMessage(const char* topic, const uint8_t* payload, const unsigned int length);

    virtual void setState(bool state);
    virtual bool getState();

    virtual void setLevel(uint16_t state);
    virtual uint16_t getLevel();

    virtual int getColorR();
    virtual int getColorG();
    virtual int getColorB();

    virtual void getRGBcharPtr(char* buffer);

protected:
    struct RGB m_rgb;
    bool m_state;
    uint16_t m_level;
};

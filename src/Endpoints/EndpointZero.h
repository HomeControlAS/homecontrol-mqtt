#pragma once

#include "Endpoint.h"

class EndpointZero : public Endpoint
{
public:
    EndpointZero(HomeControlMagic* hcm_ptr);

    void sendConfig();
    void sendFeedbackMessage();

    void incomingMessage(char* topic, uint8_t* payload, unsigned int length);
};

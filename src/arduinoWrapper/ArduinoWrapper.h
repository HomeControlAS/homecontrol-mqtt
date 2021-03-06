#pragma once

#include "IPAddress.h"

/**
 * This wrapper is for wrapping the Arduino IDE so that we also can run this using Linux in the future
 **/

void wrapperLoop(bool reconnect = true);
void wrapperSetup();
void wrapperSetServer(IPAddress ip);
void wrapperSetServer(uint8_t* ip);
void wrapperSetServer(char* ip);
void wrapperSetCallback(void (*callback)(const char*, const uint8_t*, const unsigned int));
bool wrapperIsMqttConnected();
void wrapperSetUsernamePassword(const char* const username, const char* const password);
void wrapperClearMessageBuffer();
void wrapperClearTopicBuffer();
char* wrapperGetTopicBuffer();
char* wrapperGetMessageBuffer();
void wrapperPublish();
#pragma once
#include <utility>
#pragma once
#include <vector>
#include <memory>
#include "SMS.hpp"


namespace ue
{

class IUserEventsHandler
{
public:
    virtual ~IUserEventsHandler() = default;
    virtual void handleViewSmsList() = 0;
    virtual void handleSingleSms(int messageIndex) = 0;
    virtual void handleSendSms(SMS sendingSMS) = 0;
    virtual void handleMenuList(unsigned int selectionIndex) = 0;
    virtual void handleSendCallAccepted(common::PhoneNumber from)=0;
    virtual void handleSendCallDropped(common::PhoneNumber from)=0;
    virtual void handleSendCallRequest(common::PhoneNumber to)=0;
    virtual void handleSendCallTalk(common::PhoneNumber to, const std::string &msg) =0;


};

class IUserPort
{
public:
    using Selection = unsigned;
    using OptionalSelection = std::pair<bool,Selection>;



    virtual ~IUserPort() = default;

    virtual void showNotConnected() = 0;
    virtual void showConnecting() = 0;
    virtual void showConnected() = 0;
    virtual void showSmsList(std::unique_ptr<std::vector<SMS>> smsList) = 0;
    virtual void smsListViewHandler(OptionalSelection messageIndex) = 0;
    virtual void composeSms() = 0;
    virtual void showSingleSms(SMS sms) = 0;
    virtual void smsNotification() = 0;
    virtual void showCalling(common::PhoneNumber from)=0;
    virtual void makeACall()=0;
    virtual void alertUser(std::string msg)=0;
    virtual void setCallMode(common::PhoneNumber partnerPhoneNumber) =0;
    virtual void waitingForCallRespond()=0;
    virtual void newCallMessage(const std::string &text)=0;

};

}

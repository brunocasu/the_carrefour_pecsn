#ifndef __THE_CARREFOUR_SOURCEA_H
#define __THE_CARREFOUR_SOURCEA_H

#include <omnetpp.h>
#include "till2queue_m.h"

using namespace omnetpp;

namespace the_carrefour {

class SourceA : public cSimpleModule
{
  private:
    cMessage *newClientMessage;
    cMessage *timerMessage;
    cOutVector partialClientsVector; // number of new clients in the timer interval
    int n_clients_sent = 0;
    int prev_count = 0;
    int partial_n = 0;
    int intital_set = 0;
    double discourage_multiplyer = 1; // multiplier to reduce client IA in discouraged mode

  public:
     SourceA();
     virtual ~SourceA();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

}; // namespace

#endif

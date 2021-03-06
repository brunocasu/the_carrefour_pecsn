#include "TillB.h"

namespace the_carrefour {

Define_Module(TillB);

void TillB::initialize()
{

}

void TillB::handleMessage(cMessage *msg)
{
    std::string message_name = msg->getName();

    Till2queue *tempMsg;
    tempMsg = (Till2queue*)msg;

    if (message_name.compare("client")==0){ // received a client
        // EV << "RECEIVED CLIENT AT TILL " << endl;
        till_number = tempMsg->getTill_n();
        beginProcTime = simTime();
        Till2queue *fix_proc = new Till2queue("fixed_proc");
        constProcVal = par("minProcInterval").doubleValue();
        scheduleAt(simTime()+constProcVal, fix_proc); // add minimum processing time
    }
    else if (message_name.compare("fixed_proc")==0){
        Till2queue *proc_job = new Till2queue("end_proc");
        procTimeVal = par("procInterval").doubleValue();
        if (FAST_QUEUE_MODE == 0){
            scheduleAt(simTime()+procTimeVal, proc_job); // add random time to processing
        }
        else if (FAST_QUEUE_MODE == 1){
            if (till_number<7){
                scheduleAt(simTime()+procTimeVal, proc_job); // Normal tills
            }
            if (till_number>=7 && till_number<10){
                if(procTimeVal > 300){scheduleAt(simTime()+procTimeVal*0.1, proc_job);}// Fast tills}
                else {scheduleAt(simTime()+procTimeVal*0.5, proc_job);} // Fast tills}
            }
        }
    }
    else if (message_name.compare("end_proc")==0){
        n_clients_proc++;
        Till2queue *job = new Till2queue("empty");
        job->setProcTime(simTime() - beginProcTime);
        send(job, "out");
        // EV << "TILL " << " PROCESSED CLIENT" << endl;
    }
    delete msg;
}

void TillB::finish()
{
    EV << "TILL " << till_number << " PROCESSED CLIENTS: " << n_clients_proc << endl;
}

}; // namespace



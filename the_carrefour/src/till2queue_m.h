//
// Generated file, do not edit! Created by nedtool 5.7 from till2queue.msg.
//

#ifndef __THE_CARREFOUR_TILL2QUEUE_M_H
#define __THE_CARREFOUR_TILL2QUEUE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0507
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace the_carrefour {

/**
 * Class generated from <tt>till2queue.msg:21</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet Till2queue
 * {
 *     int till_n;
 *     string msg;
 *     simtime_t procTime;
 * }
 * </pre>
 */
class Till2queue : public ::omnetpp::cPacket
{
  protected:
    int till_n;
    ::omnetpp::opp_string msg;
    ::omnetpp::simtime_t procTime;

  private:
    void copy(const Till2queue& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Till2queue&);

  public:
    Till2queue(const char *name=nullptr, short kind=0);
    Till2queue(const Till2queue& other);
    virtual ~Till2queue();
    Till2queue& operator=(const Till2queue& other);
    virtual Till2queue *dup() const override {return new Till2queue(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getTill_n() const;
    virtual void setTill_n(int till_n);
    virtual const char * getMsg() const;
    virtual void setMsg(const char * msg);
    virtual ::omnetpp::simtime_t getProcTime() const;
    virtual void setProcTime(::omnetpp::simtime_t procTime);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Till2queue& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Till2queue& obj) {obj.parsimUnpack(b);}

} // namespace the_carrefour

#endif // ifndef __THE_CARREFOUR_TILL2QUEUE_M_H


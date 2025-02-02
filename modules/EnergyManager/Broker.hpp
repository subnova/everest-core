// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#ifndef BROKER_HPP
#define BROKER_HPP

#include "Market.hpp"
#include "Offer.hpp"

namespace module {

// base class for different Brokers
class Broker {
public:
    Broker(Market& market);
    virtual ~Broker(){};
    virtual bool trade(Offer& offer) = 0;
    Market& get_local_market();

protected:
    // reference to local market at the broker's node
    Market& local_market;
    std::vector<bool> first_trade;
};

} // namespace module

#endif // BROKER_HPP

/*
 * \copyright Copyright 2015 All Rights Reserved.
 * \license @{
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @}
 */

#ifndef QUANTSYSTEM_COMMON_DATA_MARKET_TRADEBARS_H_
#define QUANTSYSTEM_COMMON_DATA_MARKET_TRADEBARS_H_

#include <glog/logging.h>

#include <string>
using std::string;
#include <map>
using std::map;
#include <vector>
using std::vector;
#include "quantsystem/common/global.h"
#include "quantsystem/common/data/base_data.h"
#include "quantsystem/common/time/date_time.h"
#include "quantsystem/common/data/market/tick.h"
#include "quantsystem/common/strings/stringpiece.h"
#include "quantsystem/common/data/market/tradebar.h"
#include "quantsystem/common/data/subscription_data_config.h"

namespace quantsystem {
namespace data {
namespace market {
/**
 * Collection of TradeBars to create a data type for generic data handler.
 *
 * @ingroup CommonBaseData
 */
class TradeBars : public BaseData {
 public:
  /**
   * Standard construct.
   */
  TradeBars();

  /**
   * Default constructor for tradebars collection at this time frontier:
   * all tradebars in this collection occurred at this time.
   * @param frontier date time
   */
  explicit TradeBars(const DateTime& frontier);

  /**
   * Standard destructor.
   */
  virtual ~TradeBars();

  /**
   * Convert data source into BaseData objects.
   *
   * Reader converts each line of the data source into BaseData objects.
   * Each data type creates its own factory method,
   * and returns a new instance of the object each time it is called.
   *
   * @param config Subscription data config setup object.
   * @param line Line of the source document.
   * @param date Date of the requested data.
   * @param datafeed Type of datafeed - a live or backtest feed.
   * @return Instance of BaseData object generated by this line of the CSV.
   */
  virtual BaseData* Reader(const SubscriptionDataConfig& config,
                          const StringPiece& line, const DateTime& date,
                           DataFeedEndpoint::Enum datafeed) {
    LOG(FATAL) << "Ticks doesnot implement this method";
    return NULL;
  }

  /**
   * Get the source file for this tick subscription.
   *
   * Return the URL string source of the file.
   * This will be converted to a stream.
   *
   * @param config Configuration object.
   * @param date Date of this souce file.
   * @param data_feed Type of datafeed - a live or backtest feed.
   * @retrurn URL of source file.
   */
  virtual string GetSource(const SubscriptionDataConfig& config,
                           const DateTime& date,
                           DataFeedEndpoint::Enum data_feed) {
    LOG(FATAL) << "Ticks doesnot implement this method";
    return "";
  }

  /**
   * Return a new instance clone of this object.
   *
   * @return A new instance clone of this object.
   */
  virtual BaseData* Clone() const {
    LOG(FATAL) << "TradeBars doesnot implement this method";
    return NULL;
  }

  void Add(const string& key, TradeBar* value);

  int Count() const {
    return trade_bars_.size();
  }

  void Remove(const string& key);

  bool Contains(const string& key) const;

  void Clear();

 private:
  typedef map<const string, TradeBar*> TradeBarMap;
  TradeBarMap trade_bars_;
};

}  // namespace market
}  // namespace data
}  // namespace quantsystem

#endif  // QUANTSYSTEM_COMMON_DATA_MARKET_TRADEBARS_H_

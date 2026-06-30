module airline_ticket;

/**
 * @brief 计算机票实际价格
 * @return 机票价格（美元）
 * @note 精英会员免费，普通乘客 = 里程 × 0.1
 */
auto AirlineTicket::calculatePriceInDollars() const -> double
{
	// 精英超级奖励会员可免费乘坐航班
	if (hasEliteSuperRewardsStatus()) {
		return 0;
	}

	// 普通乘客计费规则：里程数 × 0.1 美元/英里
	return getNumberOfMiles() * 0.1;
}

/**
 * @brief 获取乘客姓名
 * @return 乘客姓名
 */
auto AirlineTicket::getPassengerName() const -> const std::string&
{
	return m_passengerName;
}

/**
 * @brief 设置乘客姓名
 * @param name 乘客姓名
 */
auto AirlineTicket::setPassengerName(const std::string& name) -> void
{
	m_passengerName = name;
}

/**
 * @brief 获取累计飞行里程
 * @return 里程数
 */
auto AirlineTicket::getNumberOfMiles() const -> int
{
	return m_numberOfMiles;
}

/**
 * @brief 设置累计飞行里程
 * @param miles 里程数
 */
auto AirlineTicket::setNumberOfMiles(const int miles) -> void
{
	m_numberOfMiles = miles;
}

/**
 * @brief 获取精英会员状态
 * @return 会员状态
 */
auto AirlineTicket::hasEliteSuperRewardsStatus() const -> bool
{
	return m_hasEliteSuperRewardsStatus;
}

/**
 * @brief 设置精英会员状态
 * @param status 会员状态
 */
auto AirlineTicket::setHasEliteSuperRewardsStatus(const bool status) -> void
{
	m_hasEliteSuperRewardsStatus = status;
}
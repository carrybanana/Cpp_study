export module airline_ticket;

import std;

/// 导出类：航空机票
export class AirlineTicket
{
public:
	/**
	 * @brief 计算机票价格（美元）
	 * @return 最终机票价格，精英会员免费，普通乘客按里程计费
	 */
	[[nodiscard]]
	auto calculatePriceInDollars() const -> double;

	/**
	 * @brief 获取乘客姓名
	 * @return 乘客姓名字符串（const 引用，禁止修改）
	 */
	[[nodiscard]]
	auto getPassengerName() const -> const std::string&;

	/**
	 * @brief 设置乘客姓名
	 * @param name 乘客姓名
	 */
	auto setPassengerName(const std::string& name) -> void;

	/**
	 * @brief 获取累计飞行里程
	 * @return 飞行里程数
	 */
	[[nodiscard]]
	auto getNumberOfMiles() const -> int;

	/**
	 * @brief 设置累计飞行里程
	 * @param miles 飞行里程数
	 */
	auto setNumberOfMiles(int miles) -> void;

	/**
	 * @brief 判断是否为精英超级奖励会员
	 * @return true=是精英会员，false=普通乘客
	 */
	[[nodiscard]]
	auto hasEliteSuperRewardsStatus() const -> bool;

	/**
	 * @brief 设置精英会员资格
	 * @param status true=拥有精英资格，false=无
	 */
	auto setHasEliteSuperRewardsStatus(bool status) -> void;

	/**
	 *
	 *
	 */
	[[nodiscard("必须处理是否存在常旅客编号的状态")]]
	auto getFrequentFlyerNumber() const -> std::optional<int>;
	auto setFrequentFlyerNumber(int number) -> void;

private:
	std::string m_passengerName{ "Unknown Passenger" };	///< 乘客姓名
	int m_numberOfMiles{ 0 };								///< 累计飞行里程
	bool m_hasEliteSuperRewardsStatus{ false };				///< 是否为精英会员
	std::optional<int> m_frequentFlyerNumber;
};

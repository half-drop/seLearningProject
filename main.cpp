#include <iostream>
#include <string>
#include <vector>

// 实时监测与数据结构
struct EnvironmentData {
	float soilMoisture;
	float temperature;
	float lightIntensity;
};

// 前台用户模块
class UserFrontend {
private:
	EnvironmentData currentData;
public:
	void collectRealTimeData(float soilMoisture, float temperature, float lightIntensity) {
		currentData = { soilMoisture, temperature, lightIntensity };
		std::cout << "实时数据采集完成："
			<< "\n土壤湿度：" << currentData.soilMoisture
			<< "\n温度：" << currentData.temperature
			<< "\n光照：" << currentData.lightIntensity
			<< std::endl;
	}

	void productionDecisionSupport() {
		// 基于当前数据提供管理建议
		std::cout << "基于当前数据提供种植和作物管理建议。" << std::endl;
		if (currentData.soilMoisture < 30) {
			std::cout << "建议增加灌溉。" << std::endl;
		}
		if (currentData.temperature < 10) {
			std::cout << "建议采取保暖措施。" << std::endl;
		}
	}
};

// 市场信息数据结构
struct MarketData {
	std::string cropName;
	float price;
};

// 农场后台管理模块
class FarmBackendManagement {
private:
	std::vector<MarketData> marketPrices;
public:
	void updateMarketPrices(const std::vector<MarketData>& prices) {
		marketPrices = prices;
		std::cout << "市场价格已更新。" << std::endl;
	}

	void marketInfoAndSales() {
		std::cout << "当前市场价格信息：" << std::endl;
		for (const auto& data : marketPrices) {
			std::cout << "作物：" << data.cropName << "，价格：" << data.price << std::endl;
		}
	}

	void intelligentIrrigationAndFertilization(EnvironmentData& envData) {
		std::cout << "根据环境数据进行智能灌溉和施肥。" << std::endl;
		if (envData.soilMoisture < 30) {
			std::cout << "灌溉系统启动。" << std::endl;
			envData.soilMoisture += 10; // 模拟灌溉增加湿度
		}
		std::cout << "施肥已根据作物需求完成。" << std::endl;
	}

	void pestMonitoringAndAlert() {
		std::cout << "病虫害监测系统正常，未发现异常。" << std::endl;
	}
};

// 管理员后台模块
class AdminBackend {
public:
	void dataManagement() {
		std::cout << "维护用户和系统数据的安全性和完整性。" << std::endl;
	}

	void systemMonitoringAndMaintenance() {
		std::cout << "系统运行正常，未发现异常。" << std::endl;
	}
};

// 测试主函数
int main() {
	// 创建各个模块的实例
	UserFrontend userFrontend;
	FarmBackendManagement farmBackend;
	AdminBackend adminBackend;

	// 模拟实时数据采集
	userFrontend.collectRealTimeData(28.5, 18.0, 1200.0);
	userFrontend.productionDecisionSupport();
	std::cout << "————————————————————" << std::endl;
	// 更新市场价格信息
	std::vector<MarketData> marketPrices = {
		{"小麦", 2.5},
		{"玉米", 3.0},
		{"大豆", 1.8}
	};
	farmBackend.updateMarketPrices(marketPrices);
	farmBackend.marketInfoAndSales();
	std::cout << "————————————————————" << std::endl;
	// 模拟智能灌溉和施肥
	EnvironmentData envData = { 28.5, 18.0, 1200.0 };
	farmBackend.intelligentIrrigationAndFertilization(envData);
	farmBackend.pestMonitoringAndAlert();
	std::cout << "————————————————————" << std::endl;
	// 管理员后台操作
	adminBackend.dataManagement();
	adminBackend.systemMonitoringAndMaintenance();

	return 0;
}
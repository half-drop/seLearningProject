#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <fstream>
#include <ctime>
#include <limits>

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
	void collectRealTimeData() {
		std::cout << "请输入土壤湿度（%）、温度（℃）和光照强度（lux）:" << std::endl;
		if (!(std::cin >> currentData.soilMoisture >> currentData.temperature >> currentData.lightIntensity)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "输入格式错误，请按正确格式重新输入！" << std::endl;
			collectRealTimeData();
		}
		else {
			std::cout << "实时数据采集完成："
				<< "\n土壤湿度：" << currentData.soilMoisture
				<< "\n温度：" << currentData.temperature
				<< "\n光照：" << currentData.lightIntensity
				<< std::endl;
		}
	}

	void productionDecisionSupport() {
		std::cout << "基于当前数据提供种植和作物管理建议：" << std::endl;
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
	void updateMarketPrices() {
		int n;
		std::cout << "请输入市场数据数量：" << std::endl;
		if (!(std::cin >> n) || n < 1) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "输入的数量无效，请重新输入有效的正整数！" << std::endl;
			updateMarketPrices();
			return;
		}

		marketPrices.resize(n);
		std::cout << "请输入作物名称和价格：" << std::endl;
		for (int i = 0; i < n; ++i) {
			if (!(std::cin >> marketPrices[i].cropName >> marketPrices[i].price)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "输入格式错误，请重新输入市场数据：" << std::endl;
				i--;
			}
		}
		std::cout << "市场价格已更新。" << std::endl;
	}

	void marketInfoAndSales() {
		std::cout << "当前市场价格信息：" << std::endl;
		for (const auto& data : marketPrices) {
			std::cout << "作物：" << data.cropName << "，价格：" << data.price << "元" << std::endl;
		}
	}

	void intelligentIrrigationAndFertilization(EnvironmentData& envData) {
		std::cout << "根据环境数据进行智能灌溉和施肥：" << std::endl;
		if (envData.soilMoisture < 30) {
			std::cout << "灌溉系统启动，正在增加土壤湿度。" << std::endl;
			envData.soilMoisture += 10; // 模拟灌溉增加湿度
		}
		std::cout << "施肥已根据作物需求完成。" << std::endl;
	}

	void pestMonitoringAndAlert() {
		std::cout << "病虫害监测系统正在运行，未发现异常。" << std::endl;
	}
};

// 管理员后台模块
struct UserInfo {
	std::string username;
	std::string password; // 实际应用中需要对密码进行加密处理
	bool isAdmin;
};

// 管理员后台模块
class AdminBackend {
private:
	std::map<std::string, UserInfo> users;
	std::ofstream logFile;

public:
	AdminBackend() {
		logFile.open("system_log.txt", std::ios::app); // 追加模式
		logFile << currentTime() << " - 系统启动，日志文件已打开。" << std::endl;
	}

	~AdminBackend() {
		logFile << currentTime() << " - 系统关闭，日志文件即将关闭。" << std::endl;
		logFile.close();
	}

	void addUser(const std::string& username, const std::string& password, bool isAdmin) {
		if (users.find(username) != users.end()) {
			logFile << currentTime() << " - 添加用户失败：用户已存在。" << std::endl;
			std::cout << "用户已存在，无法添加！" << std::endl;
		}
		else {
			users[username] = { username, password, isAdmin };
			logFile << currentTime() << " - 用户 " << username << " 成功添加。" << std::endl;
			std::cout << "用户 " << username << " 已添加。" << std::endl;
		}
	}

	void deleteUser(const std::string& username) {
		if (users.find(username) == users.end()) {
			logFile << currentTime() << " - 删除用户失败：用户不存在。" << std::endl;
			std::cout << "用户不存在，无法删除！" << std::endl;
		}
		else {
			users.erase(username);
			logFile << currentTime() << " - 用户 " << username << " 已删除。" << std::endl;
			std::cout << "用户 " << username << " 已删除。" << std::endl;
		}
	}

	void dataManagement() {
		std::cout << "维护用户和系统数据的安全性和完整性。" << std::endl;
		logFile << currentTime() << " - 正在进行数据维护。" << std::endl;
	}

	void systemMonitoringAndMaintenance() {
		std::cout << "系统运行监测中，一切正常。" << std::endl;
		logFile << currentTime() << " - 系统运行监测中，一切正常。" << std::endl;
	}

	std::string currentTime() {
		time_t now = time(nullptr);
		struct tm timeinfo;
		char buffer[80];

		// 使用 localtime_s 替代 localtime
		localtime_s(&timeinfo, &now); // 更安全的调用，避免潜在的安全问题
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
		return std::string(buffer);
	}
};

void motd() {
	std::cout << "========================================\n";
	std::cout << " 欢迎使用农场管理系统\n";
	std::cout << " 本系统提供实时数据采集、市场价格更新、\n";
	std::cout << " 智能灌溉施肥和后台管理功能。\n";
	std::cout << " 开发者：[软件工程213 张馨元组]\n";
	std::cout << " 版本：1.0\n";
	std::cout << "========================================\n";
}
// 测试主函数
int main() {
	// 创建各个模块的实例
	UserFrontend userFrontend;
	FarmBackendManagement farmBackend;
	AdminBackend adminBackend;

	int choice = 0;
	motd(); // 显示欢迎信息
	do {
		// 显示菜单
		system("pause");
		system("cls");
		std::cout << "请选择操作：" << std::endl;
		std::cout << "1. 模拟实时数据采集" << std::endl;
		std::cout << "2. 更新市场价格信息" << std::endl;
		std::cout << "3. 模拟智能灌溉和施肥" << std::endl;
		std::cout << "4. 管理员后台操作" << std::endl;
		std::cout << "5. 退出程序" << std::endl;
		std::cout << "请输入选项（1-5）: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			// 模拟实时数据采集
			userFrontend.collectRealTimeData();
			userFrontend.productionDecisionSupport();
			break;
		case 2:
			// 更新市场价格信息
			farmBackend.updateMarketPrices();
			farmBackend.marketInfoAndSales();
			break;
		case 3:
			// 模拟智能灌溉和施肥
		{
			EnvironmentData envData = { 28.5, 18.0, 1200.0 };
			farmBackend.intelligentIrrigationAndFertilization(envData);
			farmBackend.pestMonitoringAndAlert();
		}
		break;
		case 4:
			// 管理员后台操作
			adminBackend.dataManagement();
			adminBackend.systemMonitoringAndMaintenance();
			break;
		case 5:
			std::cout << "退出程序中..." << std::endl;
			break;
		default:
			std::cout << "无效输入，请输入1-5之间的数字。" << std::endl;
			break;
		}
		std::cout << "————————————————————" << std::endl;
	} while (choice != 5);

	return 0;
}
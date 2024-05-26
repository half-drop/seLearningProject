#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <fstream>
#include <ctime>
#include <limits>

// ʵʱ��������ݽṹ
struct EnvironmentData {
	float soilMoisture;
	float temperature;
	float lightIntensity;
};

// ǰ̨�û�ģ��
class UserFrontend {
private:
	EnvironmentData currentData;

public:
	void collectRealTimeData() {
		std::cout << "����������ʪ�ȣ�%�����¶ȣ��棩�͹���ǿ�ȣ�lux��:" << std::endl;
		if (!(std::cin >> currentData.soilMoisture >> currentData.temperature >> currentData.lightIntensity)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�����ʽ�����밴��ȷ��ʽ�������룡" << std::endl;
			collectRealTimeData();
		}
		else {
			std::cout << "ʵʱ���ݲɼ���ɣ�"
				<< "\n����ʪ�ȣ�" << currentData.soilMoisture
				<< "\n�¶ȣ�" << currentData.temperature
				<< "\n���գ�" << currentData.lightIntensity
				<< std::endl;
		}
	}

	void productionDecisionSupport() {
		std::cout << "���ڵ�ǰ�����ṩ��ֲ����������飺" << std::endl;
		if (currentData.soilMoisture < 30) {
			std::cout << "�������ӹ�ȡ�" << std::endl;
		}
		if (currentData.temperature < 10) {
			std::cout << "�����ȡ��ů��ʩ��" << std::endl;
		}
	}
};

// �г���Ϣ���ݽṹ
struct MarketData {
	std::string cropName;
	float price;
};

// ũ����̨����ģ��
class FarmBackendManagement {
private:
	std::vector<MarketData> marketPrices;

public:
	void updateMarketPrices() {
		int n;
		std::cout << "�������г�����������" << std::endl;
		if (!(std::cin >> n) || n < 1) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�����������Ч��������������Ч����������" << std::endl;
			updateMarketPrices();
			return;
		}

		marketPrices.resize(n);
		std::cout << "�������������ƺͼ۸�" << std::endl;
		for (int i = 0; i < n; ++i) {
			if (!(std::cin >> marketPrices[i].cropName >> marketPrices[i].price)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "�����ʽ���������������г����ݣ�" << std::endl;
				i--;
			}
		}
		std::cout << "�г��۸��Ѹ��¡�" << std::endl;
	}

	void marketInfoAndSales() {
		std::cout << "��ǰ�г��۸���Ϣ��" << std::endl;
		for (const auto& data : marketPrices) {
			std::cout << "���" << data.cropName << "���۸�" << data.price << "Ԫ" << std::endl;
		}
	}

	void intelligentIrrigationAndFertilization(EnvironmentData& envData) {
		std::cout << "���ݻ������ݽ������ܹ�Ⱥ�ʩ�ʣ�" << std::endl;
		if (envData.soilMoisture < 30) {
			std::cout << "���ϵͳ������������������ʪ�ȡ�" << std::endl;
			envData.soilMoisture += 10; // ģ��������ʪ��
		}
		std::cout << "ʩ���Ѹ�������������ɡ�" << std::endl;
	}

	void pestMonitoringAndAlert() {
		std::cout << "���溦���ϵͳ�������У�δ�����쳣��" << std::endl;
	}
};

// ����Ա��̨ģ��
struct UserInfo {
	std::string username;
	std::string password; // ʵ��Ӧ������Ҫ��������м��ܴ���
	bool isAdmin;
};

// ����Ա��̨ģ��
class AdminBackend {
private:
	std::map<std::string, UserInfo> users;
	std::ofstream logFile;

public:
	AdminBackend() {
		logFile.open("system_log.txt", std::ios::app); // ׷��ģʽ
		logFile << currentTime() << " - ϵͳ��������־�ļ��Ѵ򿪡�" << std::endl;
	}

	~AdminBackend() {
		logFile << currentTime() << " - ϵͳ�رգ���־�ļ������رա�" << std::endl;
		logFile.close();
	}

	void addUser(const std::string& username, const std::string& password, bool isAdmin) {
		if (users.find(username) != users.end()) {
			logFile << currentTime() << " - ����û�ʧ�ܣ��û��Ѵ��ڡ�" << std::endl;
			std::cout << "�û��Ѵ��ڣ��޷���ӣ�" << std::endl;
		}
		else {
			users[username] = { username, password, isAdmin };
			logFile << currentTime() << " - �û� " << username << " �ɹ���ӡ�" << std::endl;
			std::cout << "�û� " << username << " ����ӡ�" << std::endl;
		}
	}

	void deleteUser(const std::string& username) {
		if (users.find(username) == users.end()) {
			logFile << currentTime() << " - ɾ���û�ʧ�ܣ��û������ڡ�" << std::endl;
			std::cout << "�û������ڣ��޷�ɾ����" << std::endl;
		}
		else {
			users.erase(username);
			logFile << currentTime() << " - �û� " << username << " ��ɾ����" << std::endl;
			std::cout << "�û� " << username << " ��ɾ����" << std::endl;
		}
	}

	void dataManagement() {
		std::cout << "ά���û���ϵͳ���ݵİ�ȫ�Ժ������ԡ�" << std::endl;
		logFile << currentTime() << " - ���ڽ�������ά����" << std::endl;
	}

	void systemMonitoringAndMaintenance() {
		std::cout << "ϵͳ���м���У�һ��������" << std::endl;
		logFile << currentTime() << " - ϵͳ���м���У�һ��������" << std::endl;
	}

	std::string currentTime() {
		time_t now = time(nullptr);
		struct tm timeinfo;
		char buffer[80];

		// ʹ�� localtime_s ��� localtime
		localtime_s(&timeinfo, &now); // ����ȫ�ĵ��ã�����Ǳ�ڵİ�ȫ����
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
		return std::string(buffer);
	}
};

void motd() {
	std::cout << "========================================\n";
	std::cout << " ��ӭʹ��ũ������ϵͳ\n";
	std::cout << " ��ϵͳ�ṩʵʱ���ݲɼ����г��۸���¡�\n";
	std::cout << " ���ܹ��ʩ�ʺͺ�̨�����ܡ�\n";
	std::cout << " �����ߣ�[�������213 ��ܰԪ��]\n";
	std::cout << " �汾��1.0\n";
	std::cout << "========================================\n";
}
// ����������
int main() {
	// ��������ģ���ʵ��
	UserFrontend userFrontend;
	FarmBackendManagement farmBackend;
	AdminBackend adminBackend;

	int choice = 0;
	motd(); // ��ʾ��ӭ��Ϣ
	do {
		// ��ʾ�˵�
		system("pause");
		system("cls");
		std::cout << "��ѡ�������" << std::endl;
		std::cout << "1. ģ��ʵʱ���ݲɼ�" << std::endl;
		std::cout << "2. �����г��۸���Ϣ" << std::endl;
		std::cout << "3. ģ�����ܹ�Ⱥ�ʩ��" << std::endl;
		std::cout << "4. ����Ա��̨����" << std::endl;
		std::cout << "5. �˳�����" << std::endl;
		std::cout << "������ѡ�1-5��: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			// ģ��ʵʱ���ݲɼ�
			userFrontend.collectRealTimeData();
			userFrontend.productionDecisionSupport();
			break;
		case 2:
			// �����г��۸���Ϣ
			farmBackend.updateMarketPrices();
			farmBackend.marketInfoAndSales();
			break;
		case 3:
			// ģ�����ܹ�Ⱥ�ʩ��
		{
			EnvironmentData envData = { 28.5, 18.0, 1200.0 };
			farmBackend.intelligentIrrigationAndFertilization(envData);
			farmBackend.pestMonitoringAndAlert();
		}
		break;
		case 4:
			// ����Ա��̨����
			adminBackend.dataManagement();
			adminBackend.systemMonitoringAndMaintenance();
			break;
		case 5:
			std::cout << "�˳�������..." << std::endl;
			break;
		default:
			std::cout << "��Ч���룬������1-5֮������֡�" << std::endl;
			break;
		}
		std::cout << "����������������������������������������" << std::endl;
	} while (choice != 5);

	return 0;
}
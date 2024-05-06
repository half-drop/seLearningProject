#include <iostream>
#include <string>
#include <vector>

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
	void collectRealTimeData(float soilMoisture, float temperature, float lightIntensity) {
		currentData = { soilMoisture, temperature, lightIntensity };
		std::cout << "ʵʱ���ݲɼ���ɣ�"
			<< "\n����ʪ�ȣ�" << currentData.soilMoisture
			<< "\n�¶ȣ�" << currentData.temperature
			<< "\n���գ�" << currentData.lightIntensity
			<< std::endl;
	}

	void productionDecisionSupport() {
		// ���ڵ�ǰ�����ṩ������
		std::cout << "���ڵ�ǰ�����ṩ��ֲ����������顣" << std::endl;
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
	void updateMarketPrices(const std::vector<MarketData>& prices) {
		marketPrices = prices;
		std::cout << "�г��۸��Ѹ��¡�" << std::endl;
	}

	void marketInfoAndSales() {
		std::cout << "��ǰ�г��۸���Ϣ��" << std::endl;
		for (const auto& data : marketPrices) {
			std::cout << "���" << data.cropName << "���۸�" << data.price << std::endl;
		}
	}

	void intelligentIrrigationAndFertilization(EnvironmentData& envData) {
		std::cout << "���ݻ������ݽ������ܹ�Ⱥ�ʩ�ʡ�" << std::endl;
		if (envData.soilMoisture < 30) {
			std::cout << "���ϵͳ������" << std::endl;
			envData.soilMoisture += 10; // ģ��������ʪ��
		}
		std::cout << "ʩ���Ѹ�������������ɡ�" << std::endl;
	}

	void pestMonitoringAndAlert() {
		std::cout << "���溦���ϵͳ������δ�����쳣��" << std::endl;
	}
};

// ����Ա��̨ģ��
class AdminBackend {
public:
	void dataManagement() {
		std::cout << "ά���û���ϵͳ���ݵİ�ȫ�Ժ������ԡ�" << std::endl;
	}

	void systemMonitoringAndMaintenance() {
		std::cout << "ϵͳ����������δ�����쳣��" << std::endl;
	}
};

// ����������
int main() {
	// ��������ģ���ʵ��
	UserFrontend userFrontend;
	FarmBackendManagement farmBackend;
	AdminBackend adminBackend;

	// ģ��ʵʱ���ݲɼ�
	userFrontend.collectRealTimeData(28.5, 18.0, 1200.0);
	userFrontend.productionDecisionSupport();
	std::cout << "����������������������������������������" << std::endl;
	// �����г��۸���Ϣ
	std::vector<MarketData> marketPrices = {
		{"С��", 2.5},
		{"����", 3.0},
		{"��", 1.8}
	};
	farmBackend.updateMarketPrices(marketPrices);
	farmBackend.marketInfoAndSales();
	std::cout << "����������������������������������������" << std::endl;
	// ģ�����ܹ�Ⱥ�ʩ��
	EnvironmentData envData = { 28.5, 18.0, 1200.0 };
	farmBackend.intelligentIrrigationAndFertilization(envData);
	farmBackend.pestMonitoringAndAlert();
	std::cout << "����������������������������������������" << std::endl;
	// ����Ա��̨����
	adminBackend.dataManagement();
	adminBackend.systemMonitoringAndMaintenance();

	return 0;
}
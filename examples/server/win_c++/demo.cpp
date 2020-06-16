// demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "Sdk.h"
#include <map>

int main(int argc, char ** argv)
{

	std::string public_key = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA/VweA5KME/PR7QIwe+BoWf+yM5tRVpaXWOZC7S4SeLT5zyd1gNzKjLHCxAIhsxYUnXHRCdsC+cnKTVfCBuewv7N2kZCKF+/gMiqSdfiJo3XE7lmrxpIKO6YnWt7Itq/VvMJoTO7g0KkjF/irzI+OKUj5DSZORHwulA6OXNjUJbGeMdIGX7VHgbk7dv8oqx+FE0bAQ4APtOiSs5agBRdg9De92tURcj15jztYtPvaRVn5O8ozTEui4Kh2Cmf1fPFKbv5yQyNhHaqMdI2tGPREs78wGIiHT1yOmCMeKHCVgElwwgmFnmxKYsBD9XZ9GM6wzt/95M53jh/aNp/+9Y1m0QIDAQAB";

	/**********************************************************
	* ��¼��֤
	**********************************************************/
	//�����������,�ͻ���sdk���ص�����json��
	std::string jsonobj = "{\"entity\":{\"openid\":\"1-123123\",\"account\":\"test\",\"time\":1482313093},\"sign\":\"m7JTn/y3IpB084vyeqoR9ysZ5/GeowcsO3KDrDsaa8Fof2Xjq4gKdk5eDLh0nTRxZslfbet5AWs+p1M0rtF8Jan8T2VxCW/czoCkrj4o/xnYtb3wdenCXAT7LUoydjTmd+cf0I9kw0DjkPDurrT9kNqxzw6dq1A6EFZAts4f0/H5+7kn81rzPq1RkWOM6OGm8R2D2WW/jHfqZDo1mvfZvIzkA/F0M62z2VsUK821BUkgoT23dByCdeqgx4hauJTHlnvg2/MplDYMDONHai6gTFWb4FQgY2wJq1BIWCyXgDuid6n9Ck0m6paJEfOffbK7BgwH3ssaF7xYGD2sjEuCFw==\"}";

	std::cout << jsonobj.c_str() << std::endl;
	int expire = 200;
	//���صĵ�¼����
	std::map<std::string, std::string>  retData;

	//�������
	bool ret = Sdk::loginVerify(public_key, jsonobj, expire, retData);
	if (ret)
	{
		std::cout << "login ok " << std::endl;
		for (std::map<std::string, std::string>::iterator itr = retData.begin(); itr != retData.end(); itr++)
		{
			std::cout << "ret user data key=" << itr->first.c_str() << ",value=" << itr->second.c_str() << std::endl;
		}
	}
	else
	{
		std::cout << "login verify error" << std::endl;
	}
	/**********************************************************
	* ��ֵ�ص���֤
	**********************************************************/
	// �����������
	std::map<std::string, std::string > paymentPost;
	paymentPost["account"] = "abcd";
	paymentPost["amount"] = "6.00";
	paymentPost["black_desc"] = "";
	paymentPost["channel"] = "1";
	paymentPost["currency"] = "";
	paymentPost["extra"] = "123";
	paymentPost["game_id"] = "GMG001";
	paymentPost["is_black"] = "0";
	paymentPost["is_cancel"] = "0";
	paymentPost["is_recovery"] = "0";
	paymentPost["is_test"] = "0";
	paymentPost["memo"] = "";
	paymentPost["openid"] = "1-1234";
	paymentPost["order_id"] = "1399633295037630";
	paymentPost["order_type"] = "0";
	paymentPost["original_purchase_orderid"] = "";
	paymentPost["product_id"] = "HWDPID0006";
	paymentPost["time"] = "1404975144";
	paymentPost["transaction_id"] = "1000000110081354";
	paymentPost["version"] = "8.0";
	paymentPost["zone_id"] = "1";
	paymentPost["sign"] = "MT/Wp3jz8l8HV62/OrpXdDIdEF9BGw8zCtwu8VZNaxCi52QXCC7RO2Q5yLRsQy8SmZMk0h0hsxUOXSZ8zZysUL+r/ATVknUs76zveaHROAfqhwo4sBqNA3jvnkCtbV/x9vF46vmNB7tDJcG6UDrJM5a/9Bn3Xq0ctlfSJpqJskr4dqyIlvCbQyi2YtnW2f5aNWATyNUntWtzakXYxZ7mPVT7hhspREo/3v/YcygmUHJJsJ2NnqkyWH7kV3nTTtvTQirjbzgeqnFd+KZBBHuBxOXDZInNLcaTnOQLskRddt0sYJ9/L8aDx9AvZtMe8kgQJhlNq13JOLFbCoMAEHD4Gg==";
	// ���Զ�������
	std::map<std::string, std::string> gameOrder;
	gameOrder["product_id"] = "HWDPID0006";
	gameOrder["amount"] = "6.00";

	//�������
	//���ظ���ֵƽ̨����Ϣ����,����json�����ýӿڵ�����
	std::string  retString = "{\"code\":2,\"msg\":\"ǩ����֤ʧ��\"}";

	if (!Sdk::paymentVerify(public_key, paymentPost))
	{ //��֤ʧ����
		retString = "{\"code\":2,\"msg\":\"ǩ����֤ʧ��\"}";
		return 0;
	}
	else
	{
		//��Ϸ����˸���order_id�ж϶����Ƿ��Ѿ����������Ϸ���������ʵ��
		//���Զ����������Ϸ��������Զ���֪ͨ���򷵻�echo '{"code":2,"msg":"��������Զ���֪ͨ"}';
		if (paymentPost["is_test"] == "1")
		{
			retString = "{\"code\":2,\"msg\":\"��������Զ���֪ͨ\"}";
			return 0;
		}
		//������ض�������Ϸ���ܷ�������Ϸ���յ����ඩ��֪ͨʱ������ͨ���ʼ���������ʽ�����û���ֵ������ԭ�����ν������;
		if (paymentPost["is_black"] == "1") {
			retString = "{\"code\":0,\"msg\":\"������ض���֪ͨ\"}";
			return 0;
		}

		//�ָ����򶩵�����ƻ�����ȸ�֧������������Ʒ���ָܻ������������Ϸ���յ����ඩ��֪ͨʱ���������ʶ����������֧����������
		if (paymentPost["is_recovery"] == "1") {
			retString = "{\"code\":0,\"msg\":\"�ָ����򶩵�֪ͨ\"}";
			return 0;
		}

		//ȡ�����򶩵������Զ�������������Ʒ����ȡ�������������Ϸ���յ����ඩ��֪ͨʱ���볷��֮ǰ�Ķ�������״̬������ʶԭ������Ʒ������
		if (paymentPost["is_cancel"] == "1") {
			retString = "{\"code\":0,\"msg\":\"ȡ�����򶩵�֪ͨ\"}";
			return 0;
		}

		//��֤product_id�ͽ���Ƿ�ƥ��
		if (gameOrder["product_id"] != paymentPost["product_id"]) {
			retString = "{\"code\":2,\"msg\":\"��Ʒ������\"}";
			return 0;
		}
		//��֤����Ƿ���ȷ
		if (gameOrder["amount"] != paymentPost["amount"]) {
			retString = "{\"code\":2,\"msg\":\"������\"}";
			return 0;
		}

		//��Ϸ����

		//�����ɹ������أ�echo '{"code":0,"msg":"�ɹ�"}';
		retString = "{\"code\":0,\"msg\":\"�ɹ�\"}";

		//��Ϸ����ʧ�ܣ���Ҫ�ٴ�֪ͨ������
		//retString="{\"code\":1,\"msg\":\"���ݿ����\"}";

	}


	/**********************************************************
	* ��������ʵʱͳ��
	**********************************************************/
	std::string  loginKey = "111111";
	std::map<std::string, std::string > online_data;
	online_data["game_id"] = "1000";
	online_data["zone_id"] = "1";
	online_data["number"] = "99";
	if (Sdk::gameOnline(loginKey, online_data))
	{
		std::cout << "game online ok" << std::endl;
	}
	else
	{
		std::cout << "game online failed" << std::endl;
	}

	/**********************************************************
	* ��Ϸ��¼�����ϱ�
	**********************************************************/
	std::map<std::string, std::string> loginLogs;
	loginLogs["game_id"] = "1000";
	loginLogs["channel_id"] = "1";
	loginLogs["ip"] = "192.168.100.1";
	loginLogs["openid"] = "1-123456";
	loginLogs["device_udid"] = "860529036567763";
	loginLogs["device_type"] = "vivo Y51";
	loginLogs["os"] = "android";
	if (Sdk::loginLogs(loginKey, loginLogs))
	{
		std::cout << "send login logs success" << std::endl;
	}
	else
	{
		std::cout << "send login logs failed" << std::endl;
	}

	/**********************************************************
	* ������Ϣ
	**********************************************************/
	std::map<std::string, std::string> pushData;
	pushData["game_id"] = "1000";
	pushData["channel_id"] = "1";
	pushData["environment"] = "product";
	pushData["audience_type"] = "account";
	pushData["audience_list"] = "1-123456";
	pushData["message_type"] = "notify";
	pushData["title"] = "test";
	pushData["content"] = "test";

	if (Sdk::push(loginKey, pushData))
	{
		std::cout << "push success" << std::endl;
	}
	else
	{
		std::cout << "push failed" << std::endl;
	}
	return 0;

}


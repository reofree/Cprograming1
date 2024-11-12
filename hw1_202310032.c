#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void getInput(const char* prompt, int* value) {
    while (1) {
        printf("%s", prompt);
        scanf("%d", value);
        if (*value >= 0) {
            break;
        }
        else {
            printf("0 �̻��� ������ �Է��ϼ���.\n");
        }
    }
}

void calculateShinhanBenefits(int transportCost, int serviceCost, int otherCost, int* totalDiscount, float* discountRate) {
    int transportDiscount = transportCost * 10 / 100;
    if (transportDiscount > 2000) transportDiscount = 2000;

    int serviceDiscount = serviceCost * 2 / 100;
    if (serviceDiscount > 2000) serviceDiscount = 2000;

    int lastMonthUsage = transportCost + serviceCost + otherCost;
    if (lastMonthUsage >= 500000) {
        serviceDiscount += 5000;
    }
    if (serviceDiscount > 2000) serviceDiscount = 2000;

    *totalDiscount = transportDiscount + serviceDiscount;

    *discountRate = ((float)(*totalDiscount) / lastMonthUsage) * 100;
}

void calculateKookminBenefits(int transportCost, int serviceCost, int otherCost, int* totalDiscount, float* discountRate) {
    int transportDiscount = transportCost * 10 / 100;
    if (transportDiscount > 2000) transportDiscount = 2000;

    int serviceDiscount = serviceCost * 2 / 100;
    if (serviceDiscount > 8000) serviceDiscount = 8000;

    int lastMonthUsage = transportCost + serviceCost + otherCost;
    *totalDiscount = transportDiscount + serviceDiscount;

    *discountRate = ((float)(*totalDiscount) / lastMonthUsage) * 100;
}

int main() {
    int transportCost, serviceCost, otherCost;
    int sDiscount, kDiscount;
    float sRate, kRate;

    getInput("�� ��� ���߱��� ���: ", &transportCost);
    getInput("�� ��� ��Ȱ ���� ������: ", &serviceCost);
    getInput("�� ��� ��Ÿ ������: ", &otherCost);

    calculateShinhanBenefits(transportCost, serviceCost, otherCost, &sDiscount, &sRate);
    calculateKookminBenefits(transportCost, serviceCost, otherCost, &kDiscount, &kRate);

    printf("\n--- ī�� ���� ---\n");
    printf("���� K-�н� üũī���� ���� ���� �ݾ��� %d���̸�, �������� %.2f%%�Դϴ�.\n", sDiscount, sRate);
    printf("���� K-�н� üũī���� ���� ���� �ݾ��� %d���̸�, �������� %.2f%%�Դϴ�.\n", kDiscount, kRate);

    if (sDiscount > kDiscount) {
        printf("���� ���� K-�н� üũī�尡 ���� �����Դϴ�.\n");
    }
    else if (sDiscount < kDiscount) {
        printf("���� ���� K-�н� üũī�尡 ���� �����Դϴ�.\n");
    }
    else {
        printf("�� ī���� ������ �����ϴ�.\n");
    }

    return 0;
}

















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
            printf("0 이상의 정수를 입력하세요.\n");
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

    getInput("월 평균 대중교통 요금: ", &transportCost);
    getInput("월 평균 생활 서비스 결제액: ", &serviceCost);
    getInput("월 평균 기타 결제액: ", &otherCost);

    calculateShinhanBenefits(transportCost, serviceCost, otherCost, &sDiscount, &sRate);
    calculateKookminBenefits(transportCost, serviceCost, otherCost, &kDiscount, &kRate);

    printf("\n--- 카드 혜택 ---\n");
    printf("신한 K-패스 체크카드의 예상 할인 금액은 %d원이며, 할인율은 %.2f%%입니다.\n", sDiscount, sRate);
    printf("국민 K-패스 체크카드의 예상 할인 금액은 %d원이며, 할인율은 %.2f%%입니다.\n", kDiscount, kRate);

    if (sDiscount > kDiscount) {
        printf("따라서 신한 K-패스 체크카드가 나은 선택입니다.\n");
    }
    else if (sDiscount < kDiscount) {
        printf("따라서 국민 K-패스 체크카드가 나은 선택입니다.\n");
    }
    else {
        printf("두 카드의 혜택이 같습니다.\n");
    }

    return 0;
}

















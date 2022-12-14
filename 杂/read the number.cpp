#include<stdio.h>
int main(){
	char name[20];
	float hour,pay_rate,fedral_rate,state_rate;
	printf("Enter employee¡¯s name:");
	scanf("%s",name);
	printf("Enter number of hours worked in a week:");
	scanf("%f",&hour);
	printf("Enter hourly pay rate: ");
	scanf("%f",&pay_rate);
	printf("Enter fedral tax withholding rate:");
	scanf("%f",&fedral_rate);
	printf("Enter state tax withholding rate:");
	scanf("%f",&state_rate);
	printf("Employee Name:%s\nHours Worked:%.1f\nPay Rate: $%.2f\nGross Pay: $%.1f\n",name,hour,pay_rate,hour*pay_rate);
	printf("Deductions: \n Fedreal Withholding (%.1f%%):$%.1f\n State Withholdings (%.1f%%): $%.2f\n Total Deduction: $%.2f\n",fedral_rate*100,hour*fedral_rate*pay_rate,state_rate*100,hour*state_rate*pay_rate,hour*fedral_rate*pay_rate+hour*state_rate*pay_rate);
	printf("Net Pay:$%.2f",hour*pay_rate-hour*fedral_rate*pay_rate-hour*state_rate*pay_rate);
	return 0;
	
}

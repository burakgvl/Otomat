/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "I2C_Lcd.h"
#include "keypad.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define LEN	15

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart4;

/* USER CODE BEGIN PV */
char Key;
char SignificantKey[3];
int cntKey = 0;

uint8_t adres;

int coin;

volatile int QrFlag = 3;
volatile int cnt;
volatile int timer;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_UART4_Init(void);
/* USER CODE BEGIN PFP */

void FindSlave();
void EntrySentence();
void SuccesQrSentence();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_UART4_Init();
  /* USER CODE BEGIN 2 */
  lcd_init();



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	EntrySentence();

	if(QrFlag == 1){

		//İşlemler yapılırken yeni bir QR kodun gelip akışı bozmaması için interrupt kapatılır. İşlemler sonunda tekrar açılır.
		CLEAR_BIT(UART4->CR1, USART_CR1_RXNEIE);
		//Başarıyla okunan Qr kodun giriş cümle fonksiyonu
		SuccesQrSentence();

		do{
		//Keypad ile ürün seçimi
		do{
		Key = read_keypad ();
		if (Key!=0x01)
			{
				if(cntKey == 3) //Lcd ekrana şifreyi sırayla girmek ve diziye kaydetmek için sayaç.
					cntKey = 0;
				lcd_send_cmd (0x80|(0x60+cntKey));
				lcd_send_data(Key);
				SignificantKey[cntKey++] = Key;
			}
		}while(Key != '*' && cntKey != 3 ); //

		Key = atoi(SignificantKey); //Dizi içerisindeki int tam sayı değeri kaydediliyor.

		//Devamı SwitchCase yapısıyla motor hareket ettimek...
		switch(Key){
		case 1:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("1.MOTOR CALISTI");
			break;
		case 2:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("2.MOTOR CALISTI");
			break;
		case 3:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("3.MOTOR CALISTI");
			break;
		case 4:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("4.MOTOR CALISTI");
			break;
		case 5:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("5.MOTOR CALISTI");
			break;
		case 6:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("6.MOTOR CALISTI");
			break;
		case 7:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("7.MOTOR CALISTI");
			break;
		case 8:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("8.MOTOR CALISTI");
			break;
		case 9:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("9.MOTOR CALISTI");
			break;
		case 10:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("10.MOTOR CALISTI");
			break;
		case 11:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("11.MOTOR CALISTI");
			break;
		case 12:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("12.MOTOR CALISTI");
			break;
		case 13:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("13.MOTOR CALISTI");
			break;
		case 14:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("14.MOTOR CALISTI");
			break;
		case 15:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("15.MOTOR CALISTI");
			break;
		case 16:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("16.MOTOR CALISTI");
			break;
		case 17:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("17.MOTOR CALISTI");
			break;
		case 18:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("18.MOTOR CALISTI");
			break;
		case 19:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("19.MOTOR CALISTI");
			break;
		case 20:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("20.MOTOR CALISTI");
			break;
		case 21:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("21.MOTOR CALISTI");
			break;
		case 22:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("22.MOTOR CALISTI");
			break;
		case 23:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("23.MOTOR CALISTI");
			break;
		case 24:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("24.MOTOR CALISTI");
			break;
		case 25:
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("25.MOTOR CALISTI");
			break;
		default:
			Key = 0, cntKey = 0;
			lcd_clear();
			lcd_send_cmd (0x80|0x40);
			lcd_send_string("Hatali Giris!");

			lcd_send_cmd (0x80|0x14);
			lcd_send_string("  Tekrar Giriniz...  ");
			HAL_Delay(2000);

			lcd_send_cmd (0x80|0x00);
			lcd_send_string("  Urun No yazarak-  ");

			lcd_send_cmd (0x80|0x40);
			lcd_send_string("sonuna * koyunuz.");

			lcd_send_cmd (0x80|0x14);
			lcd_send_string("   Ornek:  12*   ");

			lcd_send_cmd (0x80|0x54);
			lcd_send_string("URUN NO:");
			break;
		}}while(!(Key>0 && Key<26));

		Key = 0, cntKey = 0, cnt = 0, QrFlag = 3;
		HAL_Delay(5000);
		//memset(SignificantKey, 0, sizeof(SignificantKey));
		lcd_clear();
		SET_BIT(UART4->CR1, USART_CR1_RXNEIE);
	}

	else if(QrFlag == 0 && timer== 0){ //Verilerin alımı bitmeden buraya girmemesi için timer koyuldu.
		CLEAR_BIT(UART4->CR1, USART_CR1_RXNEIE);
		lcd_clear();

		lcd_send_cmd (0x80|0x40);
		lcd_send_string("QrCode tanimlaniyor...");
		HAL_Delay(3000);

		lcd_send_cmd (0x80|0x40);
		lcd_send_string("   QR KOD HATALI   ");

		lcd_send_cmd (0x80|0x14);
		lcd_send_string("Tekrar Deneyiniz.");


		HAL_Delay(3000);
		cnt = 0, QrFlag = 3;
		SET_BIT(UART4->CR1, USART_CR1_RXNEIE);
	}


	/*
 	Key = read_keypad ();
	if (Key!=0x01)
	{
		key2 = Key;
	}
	 */


	/*coin= HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_0);
	if(coin == 1){

		lcd_clear();

		lcd_send_cmd (0x80|0x40);
		lcd_send_string("Para tanimlaniyor...");
		HAL_Delay(3000);

		lcd_send_cmd (0x80|0x40);
		lcd_send_string("Para tanimlandi.1TL.");

		lcd_send_cmd (0x80|0x14);
		lcd_send_string("Urun seciniz!");

	  }*/


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */




  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 9600;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* Enable UART Receive Data Register Not Empty */
  SET_BIT(UART4->CR1, USART_CR1_RXNEIE);



  /* USER CODE END UART4_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PD12 PD13 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */



void FindSlave(){

	for(adres = 0; adres <=255; adres++){
		if(HAL_I2C_IsDeviceReady(&hi2c1,adres,1,100) == HAL_OK)
			break;
	}
}

void EntrySentence(){
	lcd_send_cmd (0x80|0x00);
	lcd_send_string("Hosgeldiniz!");
	lcd_send_cmd (0x80|0x40);
	lcd_send_string("Hediye icin Barkod");
	lcd_send_cmd (0x80|0x14);
	lcd_send_string("okutunuz. Urun almak");
	lcd_send_cmd (0x80|0x54);
	lcd_send_string("icin TL atiniz.");
}

void SuccesQrSentence(){
	lcd_clear();

	lcd_send_cmd (0x80|0x40);
	lcd_send_string("QrCode tanimlaniyor...");
	HAL_Delay(2000);

	lcd_send_cmd (0x80|0x40);
	lcd_send_string("QR Kod tanimlandi...");
	HAL_Delay(2000);


	lcd_send_cmd (0x80|0x00);
	lcd_send_string("  Urun No yazarak-  ");

	lcd_send_cmd (0x80|0x40);
	lcd_send_string("sonuna * koyunuz.");

	lcd_send_cmd (0x80|0x14);
	lcd_send_string("   Ornek:  12*   ");

	lcd_send_cmd (0x80|0x54);
	lcd_send_string("URUN NO:");
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

#ifndef __SM_SWI2C_H
#define __SM_SWI2C_H

#include "sdk_errors.h"
#include "stdint.h"
#include "resources.h"
//����ʹ��IIC��ģ������ accelerate
typedef enum
{
    HR_IIC_MODULE,    //Health Rate ����
    BAT_IIC_MODULE,   //������
    MAG_IIC_MODULE,   //Magnetic Sensor �ش�
    ACC_IIC_MODULE,   //accelerate ���ټ�
    GYR_IIC_MODULE,   //gyroscope ������
    AP_IIC_MODULE,    //air pressure ��ѹ

    MAX_IIC_MODULE,   //��Ŀʹ��iic��ģ������֮��Ĳ�����δ�õ�

    TOUCH_IIC_MODULE, //������
    IT_IIC_MODULE,    //Infrared temperature ��������
    WP_IIC_MODULE,    //water temperature ˮѹ
}iic_module;

#define TRUE  1
#define FALSE 0


//����IIC�ٶ� 
#define IIC_SPEED_UPMAX    0
#define IIC_SPEED_HIGHEST  1    //�ٶ����,��Щ�����ٶȿɸ���400KHZ
#define IIC_SPEED_HIGH     2    //���٣� 400KHZ
#define IIC_SPEED_NORMAL   3    //���٣�
#define IIC_SPEED_LOW      4    //����


extern MultiSensor_s multisensor;

//**********************************************************************
// ��������: ��ʼ��iic
// ���������	
// ���ز�����
//**********************************************************************
extern void SMDrv_SWI2C_Init(void);

//**********************************************************************
// ��������: ����driver module ID��Ӳ����Ӧ��iic
// ���������	
//    modul: driver module ID,ֵ�ο�iic_module
//    u32speed: IIC�ٶ����ã�ֵ�ο�IIC_SPEED_XXX
// ���ز�����Ret_InvalidParam��Ret_OK
//**********************************************************************
extern ret_code_t SMDrv_SWI2C_Open(iic_module modul,uint32_t u32speed);

//**********************************************************************
// ��������: �ر�driver module IDӲ����Ӧ��IIC,��ʵ�ֵ͹���
// ���������	
//    modul: driver module ID,ֵ�ο�iic_module
// ���ز�����Ret_InvalidParam��Ret_OK
//**********************************************************************
extern ret_code_t SMDrv_SWI2C_Close(iic_module modul);

//**********************************************************************
// ��������: I2Cд����
// ���������	
//    modul: driver module ID,ֵ�ο�iic_module
//    deviceAddr��  ���豸��ַ
//    regAddr  ��  �����ƫ�Ƶ�ַ
// ���ز�����Ret_InvalidParam��Ret_OK
//**********************************************************************
extern ret_code_t SMDrv_SWI2C_WriteCmd(iic_module modul,uint8_t deviceAddr, uint8_t regAddr);

//**********************************************************************
// ��������:   I2Cд����
// ���������
// modul: driver module ID,ֵ�ο�iic_module
// deviceAddr��  ���豸��ַ
// regAddr  ��  �����ƫ�Ƶ�ַ
// data_Point�� ����ָ��
// length   ��  ���ݳ���
// ���ز�����   Ret_InvalidParam��Ret_OK
extern ret_code_t SMDrv_SWI2C_Write(iic_module modul,uint8_t deviceAddr, uint8_t regAddr, uint8_t* data_Point, uint16_t length);

//**********************************************************************
// ��������:   I2C������
// ���������
// modul: driver module ID,ֵ�ο�iic_module
// deviceAddr��  ���豸��ַ
// regAddr  ��  �����ƫ�Ƶ�ַ
// data_Point�� ����ָ��
// length   ��  ���ݳ���
// ���ز�����   Ret_InvalidParam��Ret_OK
//**********************************************************************
extern ret_code_t SMDrv_SWI2C_Read(iic_module modul,uint8_t deviceAddr, uint8_t regAddr, uint8_t* data_Point, uint16_t length);

//**********************************************************************
// ��������: ��ȡIIC��Դ��������driverģ��ʹ��ͬһ��iicʱ��Ҫ��������
// ���������	
//    modul: driver module ID,ֵ�ο�iic_module
//    u32timeout:�ȴ���ʱʱ��
// ���ز�����
//**********************************************************************
extern ret_code_t SMDrv_SWI2C_LockMutex(iic_module modul,uint32_t u32timeout);

//**********************************************************************
// ��������: �ͷ�IIC��Դ
// ���������	
//    modul: driver module ID,ֵ�ο�iic_module
// ���ز�����
//**********************************************************************
extern ret_code_t SMDrv_SWI2C_UnLockMutex(iic_module modul);

#endif

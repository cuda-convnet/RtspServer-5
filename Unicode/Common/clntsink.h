#ifndef __CLIENT_SINK_H__
#define __CLIENT_SINK_H__

//�ص������ļ�����
typedef int(__stdcall *pDataRec)(DWORD sid, int iusrdata, int idatatype, char* pdata, int ilen);
typedef int(__stdcall *pMsgBack)(int sid, int opt, int param1, int param2);

//------------------------------------------------------------------------------------------------------------------------------------	
//2012-07-04 lyq
//��ͼ�ص�����
typedef void(_stdcall *DrawCallBack)(DWORD sid, HDC hDC, void* pUserData);
//2012-07-04 lyq		
//------------------------------------------------------------------------------------------------------------------------------------	

class IHikClientAdviseSink
{
public:
	/******************************************************************
	��Setupʱ������,��ȡ�ܵĲ��ų���.nLengthΪ�ܵĲ��ų���,��1/64��Ϊ��λ
	*/
	virtual int OnPosLength(unsigned long nLength) = 0;

	/******************************************************************
	��Setup�󱻵���,��ʾURL�Ѿ����ɹ���,sucessΪ1��ʾ�ɹ�,0��ʾʧ��
	*/
	virtual int OnPresentationOpened(int success) = 0;

	/************************************************************************
	��Player��ֹͣ���ٺ����
	*/
	virtual int OnPresentationClosed() = 0;

	/************************************************************************
	δʹ��
	*/
	virtual int OnPreSeek(unsigned long uOldTime, unsigned long uNewTime) = 0;

	/************************************************************************
	δʹ��
	*/
	virtual int OnPostSeek(unsigned long uOldTime, unsigned long uNewTime) = 0;

	/************************************************************************
	δʹ��
	*/
	virtual int OnStop() = 0;

	/************************************************************************
	��Pauseʱ�����ã�uTimeĿǰ����0
	*/
	virtual int OnPause(unsigned long uTime) = 0;

	/************************************************************************
	�ڿ�ʼ����ʱ���ã�uTimeĿǰ����0
	*/
	virtual int OnBegin(unsigned long uTime) = 0;

	/************************************************************************
	���������ʱ���ã�uTimeĿǰ����0
	*/
	virtual int OnRandomBegin(unsigned long uTime) = 0;

	/************************************************************************
	��Setupǰ���ã�pszHost��ʾ�������ӵķ�����
	*/
	virtual int OnContacting(const char* pszHost) = 0;

	/************************************************************************
	�ڷ������˷��س�����Ϣ�ǵ��ã� pError��Ϊ������Ϣ����
	*/
	virtual int OnPutErrorMsg(const char* pError) = 0;

	/************************************************************************
	δʹ��
	*/
	virtual int OnBuffering(unsigned int uFlag, unsigned short uPercentComplete) = 0;

	virtual int OnChangeRate(int flag) = 0;

	virtual int OnDisconnect() = 0;
};

#endif

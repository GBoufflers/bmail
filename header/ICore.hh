#ifndef		__ICORE__
#define		__ICORE__

class		ICore
{

 public:
  virtual bool	sendMail() const = 0;
  virtual bool	receiveMail() = 0;
  virtual bool	deleteMail() = 0;
  virtual	~ICore() {};
};

#endif

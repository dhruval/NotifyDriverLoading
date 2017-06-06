 #include "ntddk.h"
   
VOID (Notify)( PUNICODE_STRING FullImageName,  HANDLE ProcessId,  PIMAGE_INFO ImageInfo )  
 {  
    WCHAR *drivername;  
	if(FullImageName)
    {  
		drivername = FullImageName->Buffer ;
	    DbgPrint ("[NOTIFICATION]Image '%ls' has been loaded.", drivername);
    }  
 }  
   
 VOID Unload(__in PDRIVER_OBJECT DriverObject)  
 {  
    PsRemoveLoadImageNotifyRoutine(&Notify);  
 }  
   
 NTSTATUS   DriverEntry(PDRIVER_OBJECT  DriverObject, PUNICODE_STRING RegistryPath)  
 {  
    DriverObject->DriverUnload = Unload;   
   
    PsSetLoadImageNotifyRoutine(&Notify);  
   
	return STATUS_SUCCESS;  
 }  
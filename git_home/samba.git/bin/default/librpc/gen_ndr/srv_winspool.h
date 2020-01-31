#include "bin/default/librpc/gen_ndr/ndr_winspool.h"
#ifndef __SRV_IREMOTEWINSPOOL__
#define __SRV_IREMOTEWINSPOOL__
WERROR _winspool_AsyncOpenPrinter(struct pipes_struct *p, struct winspool_AsyncOpenPrinter *r);
WERROR _winspool_AsyncAddPrinter(struct pipes_struct *p, struct winspool_AsyncAddPrinter *r);
WERROR _winspool_AsyncSetJob(struct pipes_struct *p, struct winspool_AsyncSetJob *r);
WERROR _winspool_AsyncGetJob(struct pipes_struct *p, struct winspool_AsyncGetJob *r);
WERROR _winspool_AsyncEnumJobs(struct pipes_struct *p, struct winspool_AsyncEnumJobs *r);
WERROR _winspool_AsyncAddJob(struct pipes_struct *p, struct winspool_AsyncAddJob *r);
WERROR _winspool_AsyncScheduleJob(struct pipes_struct *p, struct winspool_AsyncScheduleJob *r);
WERROR _winspool_AsyncDeletePrinter(struct pipes_struct *p, struct winspool_AsyncDeletePrinter *r);
WERROR _winspool_AsyncSetPrinter(struct pipes_struct *p, struct winspool_AsyncSetPrinter *r);
WERROR _winspool_AsyncGetPrinter(struct pipes_struct *p, struct winspool_AsyncGetPrinter *r);
WERROR _winspool_AsyncStartDocPrinter(struct pipes_struct *p, struct winspool_AsyncStartDocPrinter *r);
WERROR _winspool_AsyncStartPagePrinter(struct pipes_struct *p, struct winspool_AsyncStartPagePrinter *r);
WERROR _winspool_AsyncWritePrinter(struct pipes_struct *p, struct winspool_AsyncWritePrinter *r);
WERROR _winspool_AsyncEndPagePrinter(struct pipes_struct *p, struct winspool_AsyncEndPagePrinter *r);
WERROR _winspool_AsyncEndDocPrinter(struct pipes_struct *p, struct winspool_AsyncEndDocPrinter *r);
WERROR _winspool_AsyncAbortPrinter(struct pipes_struct *p, struct winspool_AsyncAbortPrinter *r);
WERROR _winspool_AsyncGetPrinterData(struct pipes_struct *p, struct winspool_AsyncGetPrinterData *r);
WERROR _winspool_AsyncGetPrinterDataEx(struct pipes_struct *p, struct winspool_AsyncGetPrinterDataEx *r);
WERROR _winspool_AsyncSetPrinterData(struct pipes_struct *p, struct winspool_AsyncSetPrinterData *r);
WERROR _winspool_AsyncSetPrinterDataEx(struct pipes_struct *p, struct winspool_AsyncSetPrinterDataEx *r);
WERROR _winspool_AsyncClosePrinter(struct pipes_struct *p, struct winspool_AsyncClosePrinter *r);
WERROR _winspool_AsyncAddForm(struct pipes_struct *p, struct winspool_AsyncAddForm *r);
WERROR _winspool_AsyncDeleteForm(struct pipes_struct *p, struct winspool_AsyncDeleteForm *r);
WERROR _winspool_AsyncGetForm(struct pipes_struct *p, struct winspool_AsyncGetForm *r);
WERROR _winspool_AsyncSetForm(struct pipes_struct *p, struct winspool_AsyncSetForm *r);
WERROR _winspool_AsyncEnumForms(struct pipes_struct *p, struct winspool_AsyncEnumForms *r);
WERROR _winspool_AsyncGetPrinterDriver(struct pipes_struct *p, struct winspool_AsyncGetPrinterDriver *r);
WERROR _winspool_AsyncEnumPrinterData(struct pipes_struct *p, struct winspool_AsyncEnumPrinterData *r);
WERROR _winspool_AsyncEnumPrinterDataEx(struct pipes_struct *p, struct winspool_AsyncEnumPrinterDataEx *r);
WERROR _winspool_AsyncEnumPrinterKey(struct pipes_struct *p, struct winspool_AsyncEnumPrinterKey *r);
WERROR _winspool_AsyncDeletePrinterData(struct pipes_struct *p, struct winspool_AsyncDeletePrinterData *r);
WERROR _winspool_AsyncDeletePrinterDataEx(struct pipes_struct *p, struct winspool_AsyncDeletePrinterDataEx *r);
WERROR _winspool_AsyncDeletePrinterKey(struct pipes_struct *p, struct winspool_AsyncDeletePrinterKey *r);
WERROR _winspool_AsyncXcvData(struct pipes_struct *p, struct winspool_AsyncXcvData *r);
WERROR _winspool_AsyncSendRecvBidiData(struct pipes_struct *p, struct winspool_AsyncSendRecvBidiData *r);
WERROR _winspool_AsyncCreatePrinterIC(struct pipes_struct *p, struct winspool_AsyncCreatePrinterIC *r);
WERROR _winspool_AsyncPlayGdiScriptOnPrinterIC(struct pipes_struct *p, struct winspool_AsyncPlayGdiScriptOnPrinterIC *r);
WERROR _winspool_AsyncDeletePrinterIC(struct pipes_struct *p, struct winspool_AsyncDeletePrinterIC *r);
WERROR _winspool_AsyncEnumPrinters(struct pipes_struct *p, struct winspool_AsyncEnumPrinters *r);
WERROR _winspool_AsyncAddPrinterDriver(struct pipes_struct *p, struct winspool_AsyncAddPrinterDriver *r);
WERROR _winspool_AsyncEnumPrinterDrivers(struct pipes_struct *p, struct winspool_AsyncEnumPrinterDrivers *r);
WERROR _winspool_AsyncGetPrinterDriverDirectory(struct pipes_struct *p, struct winspool_AsyncGetPrinterDriverDirectory *r);
WERROR _winspool_AsyncDeletePrinterDriver(struct pipes_struct *p, struct winspool_AsyncDeletePrinterDriver *r);
WERROR _winspool_AsyncDeletePrinterDriverEx(struct pipes_struct *p, struct winspool_AsyncDeletePrinterDriverEx *r);
WERROR _winspool_AsyncAddPrintProcessor(struct pipes_struct *p, struct winspool_AsyncAddPrintProcessor *r);
WERROR _winspool_AsyncEnumPrintProcessors(struct pipes_struct *p, struct winspool_AsyncEnumPrintProcessors *r);
WERROR _winspool_AsyncGetPrintProcessorDirectory(struct pipes_struct *p, struct winspool_AsyncGetPrintProcessorDirectory *r);
WERROR _winspool_AsyncEnumPorts(struct pipes_struct *p, struct winspool_AsyncEnumPorts *r);
WERROR _winspool_AsyncEnumMonitors(struct pipes_struct *p, struct winspool_AsyncEnumMonitors *r);
WERROR _winspool_AsyncAddPort(struct pipes_struct *p, struct winspool_AsyncAddPort *r);
WERROR _winspool_AsyncSetPort(struct pipes_struct *p, struct winspool_AsyncSetPort *r);
WERROR _winspool_AsyncAddMonitor(struct pipes_struct *p, struct winspool_AsyncAddMonitor *r);
WERROR _winspool_AsyncDeleteMonitor(struct pipes_struct *p, struct winspool_AsyncDeleteMonitor *r);
WERROR _winspool_AsyncDeletePrintProcessor(struct pipes_struct *p, struct winspool_AsyncDeletePrintProcessor *r);
WERROR _winspool_AsyncEnumPrintProcessorDatatypes(struct pipes_struct *p, struct winspool_AsyncEnumPrintProcessorDatatypes *r);
WERROR _winspool_AsyncAddPerMachineConnection(struct pipes_struct *p, struct winspool_AsyncAddPerMachineConnection *r);
WERROR _winspool_AsyncDeletePerMachineConnection(struct pipes_struct *p, struct winspool_AsyncDeletePerMachineConnection *r);
WERROR _winspool_AsyncEnumPerMachineConnections(struct pipes_struct *p, struct winspool_AsyncEnumPerMachineConnections *r);
HRESULT _winspool_SyncRegisterForRemoteNotifications(struct pipes_struct *p, struct winspool_SyncRegisterForRemoteNotifications *r);
HRESULT _winspool_SyncUnRegisterForRemoteNotifications(struct pipes_struct *p, struct winspool_SyncUnRegisterForRemoteNotifications *r);
HRESULT _winspool_SyncRefreshRemoteNotifications(struct pipes_struct *p, struct winspool_SyncRefreshRemoteNotifications *r);
HRESULT _winspool_AsyncGetRemoteNotifications(struct pipes_struct *p, struct winspool_AsyncGetRemoteNotifications *r);
HRESULT _winspool_AsyncInstallPrinterDriverFromPackage(struct pipes_struct *p, struct winspool_AsyncInstallPrinterDriverFromPackage *r);
HRESULT _winspool_AsyncUploadPrinterDriverPackage(struct pipes_struct *p, struct winspool_AsyncUploadPrinterDriverPackage *r);
HRESULT _winspool_AsyncGetCorePrinterDrivers(struct pipes_struct *p, struct winspool_AsyncGetCorePrinterDrivers *r);
HRESULT _winspool_AsyncCorePrinterDriverInstalled(struct pipes_struct *p, struct winspool_AsyncCorePrinterDriverInstalled *r);
HRESULT _winspool_AsyncGetPrinterDriverPackagePath(struct pipes_struct *p, struct winspool_AsyncGetPrinterDriverPackagePath *r);
HRESULT _winspool_AsyncDeletePrinterDriverPackage(struct pipes_struct *p, struct winspool_AsyncDeletePrinterDriverPackage *r);
WERROR _winspool_AsyncReadPrinter(struct pipes_struct *p, struct winspool_AsyncReadPrinter *r);
WERROR _winspool_AsyncResetPrinter(struct pipes_struct *p, struct winspool_AsyncResetPrinter *r);
WERROR _winspool_AsyncGetJobNamedPropertyValue(struct pipes_struct *p, struct winspool_AsyncGetJobNamedPropertyValue *r);
WERROR _winspool_AsyncSetJobNamedProperty(struct pipes_struct *p, struct winspool_AsyncSetJobNamedProperty *r);
WERROR _winspool_AsyncDeleteJobNamedProperty(struct pipes_struct *p, struct winspool_AsyncDeleteJobNamedProperty *r);
WERROR _winspool_AsyncEnumJobNamedProperties(struct pipes_struct *p, struct winspool_AsyncEnumJobNamedProperties *r);
WERROR _winspool_AsyncLogJobInfoForBranchOffice(struct pipes_struct *p, struct winspool_AsyncLogJobInfoForBranchOffice *r);
const struct api_struct *iremotewinspool_get_pipe_fns(int *n_fns);
struct rpc_srv_callbacks;
NTSTATUS rpc_iremotewinspool_init(const struct rpc_srv_callbacks *rpc_srv_cb);
NTSTATUS rpc_iremotewinspool_shutdown(void);
#endif /* __SRV_IREMOTEWINSPOOL__ */

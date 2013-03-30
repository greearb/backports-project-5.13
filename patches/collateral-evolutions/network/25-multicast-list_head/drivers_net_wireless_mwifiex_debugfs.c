--- a/drivers/net/wireless/mwifiex/debugfs.c
+++ b/drivers/net/wireless/mwifiex/debugfs.c
@@ -215,7 +215,11 @@
 
 		netdev_for_each_mc_addr(ha, netdev)
 			p += sprintf(p, "multicast_address[%d]=\"%pM\"\n",
+#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,35))
 					i++, ha->addr);
+#else
+					i++, ha->dmi_addr);
+#endif
 	}
 
 	p += sprintf(p, "num_tx_bytes = %lu\n", priv->stats.tx_bytes);
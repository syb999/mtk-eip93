/* SPDX-License-Identifier: GPL-2.0
 *
 * Copyright (C) 2019 - 2020
 *
 * Richard van Schagen <vschagen@cs.com>
 */
#ifndef _CIPHER_H_
#define _CIPHER_H_

extern struct mtk_alg_template mtk_alg_ecb_aes;
extern struct mtk_alg_template mtk_alg_cbc_aes;
extern struct mtk_alg_template mtk_alg_ctr_aes;
extern struct mtk_alg_template mtk_alg_rfc3686_aes;
extern struct mtk_alg_template mtk_alg_ecb_des;
extern struct mtk_alg_template mtk_alg_cbc_des;
extern struct mtk_alg_template mtk_alg_ecb_des3_ede;
extern struct mtk_alg_template mtk_alg_cbc_des3_ede;
extern struct mtk_alg_template mtk_alg_authenc_hmac_md5_cbc_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha1_cbc_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha224_cbc_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha256_cbc_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_md5_ctr_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha1_ctr_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha224_ctr_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha256_ctr_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_md5_rfc3686_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha1_rfc3686_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha224_rfc3686_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha256_rfc3686_aes;
extern struct mtk_alg_template mtk_alg_authenc_hmac_md5_cbc_des;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha1_cbc_des;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha224_cbc_des;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha256_cbc_des;
extern struct mtk_alg_template mtk_alg_authenc_hmac_md5_cbc_des3_ede;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha1_cbc_des3_ede;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha224_cbc_des3_ede;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha256_cbc_des3_ede;
extern struct mtk_alg_template mtk_alg_authenc_hmac_md5_ecb_null;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha1_ecb_null;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha224_ecb_null;
extern struct mtk_alg_template mtk_alg_authenc_hmac_sha256_ecb_null;
extern struct mtk_alg_template mtk_alg_echainiv_authenc_hmac_sha256_cbc_aes;

struct mtk_cipher_ctx {
	struct mtk_context		base;
	struct mtk_device		*mtk;
	struct saRecord_s		*sa;
	struct crypto_sync_skcipher	*fallback;

	/* AEAD specific */
	unsigned int		authsize;
	struct crypto_shash	*shash; /* TODO change to ahash */
	bool			aead;
};

struct mtk_cipher_reqctx {
	unsigned long int	flags;
	u32		        textsize;
	u32			ivsize;
	/* AEAD */
	u32                     assoclen;
	u32			authsize;
	/* copy in case of mis-alignment or AEAD if no-consecutive blocks */
	struct scatterlist	*sg_src;
	struct scatterlist	*sg_dst;
	int			src_nents;
	int			dst_nents;
	/* AES-CTR in case of counter overflow */
	struct scatterlist	ctr_src[2];
	struct scatterlist	ctr_dst[2];
};
#endif /* _CIPHER_H_ */

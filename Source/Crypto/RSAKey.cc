#include <Luce/Crypto/RSAKey.hh>

#if LUCE_MACRO_SUPPORTED_RVALUE_REF
#include <utility>
#endif

namespace Luce
{
	namespace Crypto
	{
		RSAKey::RSAKey()
		{}
		RSAKey::RSAKey(const std::vector<Utility::UInt8>& key)
		{
			Key_ = key;
		}
#if LUCE_MACRO_SUPPORTED_RVALUE_REF
		RSAKey::RSAKey(std::vector<Utility::UInt8>&& key)
		{
			Key_ = std::move(key);
		}
#endif
		RSAKey::RSAKey(const RSAKey& key)
		{
			Key_ = key.Key_;
		}
#if LUCE_MACRO_SUPPORTED_RVALUE_REF
		RSAKey::RSAKey(RSAKey&& key)
		{
			Key_ = std::move(key.Key_);
		}
#endif

		std::size_t RSAKey::GetSize() const
		{
			return Key_.size();
		}
		std::size_t RSAKey::GetSizeByBit() const
		{
			return Key_.size() * 8;
		}

		const RSAKey RSAKey::Empty = RSAKey();
	}
}
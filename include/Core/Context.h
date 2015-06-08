namespace Core
{
	struct Context
	{
		int majorVersion, minorVersion;
		bool isCore;

		Context()
		{
			majorVersion = 3;
			minorVersion = 3;
			isCore = true;
		}

		Context(int majorVersion, int minorVersion, bool isCore)
		{
			this->majorVersion = majorVersion;
			this->minorVersion = minorVersion;
			this->isCore = isCore;
		}

		Context(const Context& context)
		{
			majorVersion = context.majorVersion;
			minorVersion = context.minorVersion;
			isCore = context.isCore;
		}

		void operator=(const Context &context)
		{
			majorVersion = context.majorVersion;
			minorVersion = context.minorVersion;
			isCore = context.isCore;
		}
	};
}